/*
 * main.c
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 *
 * Осуществляет чтение исходных данных из файла в формате JSON,
 * расчёт траектории спуска ЛА с учётом программы изменения угла крена,
 * составление командного файла для построения всех графиков
 * и вывод этих графиков с помощью программы Gnuplot,
 * а также запись таблиц отклонений для каждой из промежуточных значений высот в HTML-файл.
 */

#include "main.h"

struct inputData input_data; // структура с исходными данными, прочитанными в файле Data.json

int main(int argc, char* argv[]) {
	int stepByStepMode=0;
	if(argc>1)
		for(int i=1;i<argc;i++)
			if (strcmp(argv[i],"-stepbystep")==0) {
				stepByStepMode = 1;
				break;
			};
	system("chcp 65001 > nul"); // кодировка UTF-8 в консоли (Windows)
	time_t start = clock();
	int e;
	if ((e = readData("Data.json", &input_data))) {
		printf("Ошибка чтения исходных данных.\n");
		return e;
	}

	/* Основной расчёт */
	double *time, *H, **values, *phi, *lambda, *G0;
	int steps = computeMain(&input_data, &time, &H, &values, &phi, &lambda,
			&G0);

	/* Графики основного расчёта */

	FILE *gpipe = fopen("commands.txt", "w");
	plot(gpipe, time, H, steps,
			"Зависимость высоты полёта ЛА при спуске в атмосфере от времени",
			NULL, "Время, сек", "Высота, км");
	if (stepByStepMode)
		pause(gpipe);
	figure(gpipe);
	plot(gpipe, lambda, phi, steps, "Трасса спуска ЛА", NULL,
			"Долгота, град.доли", "Широта, град.доли");

	double checkpoint[HEIGHT_COUNT] = { 100.0, 50.0, 45.0, 40.0, 35.0, 30.0,
			25.0, 20.0, 15.0, 10.0, 5.0 };
	char *pointNames[HEIGHT_COUNT] = { "100 км", "50 км", "45 км", "40 км",
			"35 км", "30 км", "25 км", "20 км", "15 км", "10 км", "5 км" };
	double dot[2][HEIGHT_COUNT] = { 0 };
	int currentIndex;
	for (int i = 0; i < HEIGHT_COUNT; ++i) {
		currentIndex = getHeightIndex(H, steps, checkpoint[i]);
		dot[0][i] = lambda[currentIndex];
		dot[1][i] = phi[currentIndex];
	}
	dots(gpipe, HEIGHT_COUNT, dot[0], dot[1], pointNames);

	/* Пауза, чтобы можно было сохранить график в разных масштабах */
	pause(gpipe);
	reset(gpipe); // сброс меток

	figure(gpipe);
	plot(gpipe, time, G0, steps,
			"Зависимость полной перегрузки, действующей на ЛА при спуске", NULL,
			"Время, сек", "Перегрузка, ед. g0");
	if (stepByStepMode)
		pause(gpipe);

	double *Gamma = (double*) calloc(steps, sizeof(double));
	for (int i = 0; i < steps; ++i) {
		Gamma[i] = getGamma(values[i]);
	}
	figure(gpipe);
	plot(gpipe, time, Gamma, steps,
			"Номинальная программа изменения угла скоростного крена ЛА", NULL,
			"Время, сек", "Угол крена, град");
	free(Gamma);
	if (stepByStepMode)
		pause(gpipe);

	double *v = (double*) calloc(steps, sizeof(double));
	for (int i = 0; i < steps; ++i) {
		v[i] = V(values[i]);
	}
	figure(gpipe);
	plot(gpipe, time, v, steps,
			"Зависимость относительной скорости полёта ЛА при спуске", NULL,
			"Время, сек", "Скорость, км/сек");
	free(v);
	if (stepByStepMode)
		pause(gpipe);

	/* Расчёт с разными углами */

	createHTML("tables.html"); // файл с таблицами
	char *columnNames[COLUMN_COUNT] = { "Угол крена, град",
			"Δ<sub>вост</sub>, км", "Δ<sub>сев</sub>, км",
			"n<sub>max</sub>, ед. g<sub>0</sub>" };
	double angle[ANGLE_COUNT] = { -180.0, -150.0, -120.0, -90.0, -60.0, -30.0,
			-15.0, 0.0, 15.0, 30.0, 60.0, 90.0, 120.0, 150.0, 180.0 };
	double height[TARGET_HEIGHT_COUNT] = { 50.0, 45.0, 40.0, 35.0, 30.0, 25.0,
			20.0, 15.0, 10.0 };
	double curDeltaNorth[ANGLE_COUNT] = { 0 },
			curDeltaEast[ANGLE_COUNT] = { 0 }, N[ANGLE_COUNT] = { 0 },
			table[ANGLE_COUNT][COLUMN_COUNT] = { 0 };
	for (int i = 0; i < TARGET_HEIGHT_COUNT; ++i) {
		computeAngles(ANGLE_COUNT, angle, H, height[i], values, steps, phi,
				lambda, curDeltaNorth, curDeltaEast, N);
		char title[120];
		sprintf(title, "Зона манёвра ЛА для высоты начала маневрирования %g км",
				height[i]);
		figure(gpipe);
		plot(gpipe, curDeltaEast, curDeltaNorth, ANGLE_COUNT, title, NULL,
				"Отклонение на восток, км", "Отклонение на север, км");
		dots(gpipe, ANGLE_COUNT, curDeltaEast, curDeltaNorth, NULL);
		//Запись таблицы в файл
		for (int r = 0; r < ANGLE_COUNT; ++r) {
			table[r][0] = angle[r];
			table[r][1] = curDeltaEast[r];
			table[r][2] = curDeltaNorth[r];
			table[r][3] = N[r];
		}
		writeTable(ANGLE_COUNT, COLUMN_COUNT, table, title, columnNames);
		if (stepByStepMode)
			pause(gpipe);
	}

	// Закрываем файл и высвобождаем память
	closeHTML();
	fclose(gpipe);
	free(time);
	free(H);
	for (int i = 0; i <= steps; ++i)
		free(values[i]);
	free(values);
	free(phi);
	free(lambda);
	free(G0);

	/* Вывод времени, затраченного на расчёт и запись команд */
	printf("Выполнено за %g с.\n",
			((double) (clock() - start)) / (double) CLOCKS_PER_SEC);

	/* Выполнение файла с командами в gnuplot'е */
	if(argc>1)
		for(int i=1;i<argc;i++)
			if (strcmp(argv[i],"-local")==0) {
				system("gnuplot\\bin\\gnuplot -persist commands.txt");
				return 0;
			};
	system("gnuplot -persist commands.txt");
	return 0;
}

/* Выполняет расчёт траектории основной программы */
int computeMain(struct inputData *inputData, double **time, double **H,
		double ***values, double **PHI, double **LAMBDA, double **G0) {
	int steps = (int) ((*inputData).time / (*inputData).step);
	*time = (double*) calloc(steps, sizeof(double));
	*values = (double**) calloc(steps, sizeof(double*));
	for (int i = 0; i < steps; ++i)
		(*values)[i] = (double*) calloc(6, sizeof(double));
	prepareValues(0.0, (*inputData).time, steps, (*inputData).step, *time,
			(*values), inputData);
	steps = odeCompute(ode1, steps, *time, (*values));
	*H = (double*) calloc(steps, sizeof(double));
	*PHI = (double*) calloc(steps, sizeof(double));
	*LAMBDA = (double*) calloc(steps, sizeof(double));
	*G0 = (double*) calloc(steps, sizeof(double));
	for (int i = 0; i < steps; ++i) {
		(*H)[i] = h((*values)[i]);
		(*PHI)[i] = phi((*values)[i]);
		(*LAMBDA)[i] = lambda((*values)[i]);
		(*G0)[i] = overload((*values)[i]);
	}

	return steps;
}

/* Расчёт отклонений от основной траектории, начиная с указанной высоты */
void computeAngles(int angleCount, double angle[angleCount], double *H,
		double targetH, double **values, int lastValueIndex, double *PHI,
		double *LAMBDA, double DeltaNorth[], double DeltaEast[], double N[]) {
	int heightIndex = getHeightIndex(H, lastValueIndex, targetH);
	double *currentHeightCoods[] = { &(input_data.x), &(input_data.y),
			&(input_data.z), &(input_data.Vx), &(input_data.Vy),
			&(input_data.Vz) };
	for (int i = 0; i < 6; ++i)
		*(currentHeightCoods[i]) = values[heightIndex][i];
	//Считаем для каждого угла
	for (int a = 0; a < angleCount; ++a) {
		input_data.angle_55 = input_data.angle_55_45 = input_data.angle_45 =
				angle[a];
		double *curTime, *curH, **curValues, *curPhi, *curLambda, *curOverload;
		int last = computeMain(&input_data, &curTime, &curH, &curValues,
				&curPhi, &curLambda, &curOverload);
		DeltaNorth[a] = deltaNorth(PHI[lastValueIndex - 1], curPhi[last - 1]);
		DeltaEast[a] = deltaEast(LAMBDA[lastValueIndex - 1],
				curLambda[last - 1]);
		N[a] = max(curOverload, last);
		free(curTime);
		free(curH);
		for (int i = 0; i <= last; ++i)
			free(curValues[i]);
		free(curValues);
		free(curPhi);
		free(curLambda);
	}
}

/* Возвращает индекс высоты, ближайшей к указанной */
int getHeightIndex(double *H, int count, double target) {
	int index = 0;
	for (int i = 0; i < count; ++i)
		if (fabs(H[i] - target) <= fabs(H[index] - target))
			index = i;
	return index;
}
