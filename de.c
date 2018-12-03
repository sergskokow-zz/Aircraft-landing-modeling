/*
 * de.c
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#include "inputData.h"
#include "p.h"
#include <math.h>
extern struct inputData input_data;
double K;       // величина аэродинамического качества

/* решение системы ДУ методом Эйлера */
int ode1(int count, double (*u[])(double t, double *params), double *t,
		int steps, double delta_t, double **values,
		int (*condition)(double *params)) {
	for (int i = 1; i < steps; ++i) {
		for (int j = 0; j < count; ++j)
			values[i][j] = values[i - 1][j]
					+ delta_t * u[j](t[i], values[i - 1]);
		if (!condition(values[i]))
			return i;
	}
	return count;
}

/* подготовка массива значений для расчёта */
void prepareValues(double t_begin, double t_end, int steps, double delta_t,
		double *t, double **values, struct inputData *data) {
	for (int i = 0; i < steps; ++i) {
		t[i] = t_begin;
		t_begin += delta_t;
	}
	double source[] = { (*data).x, (*data).y, (*data).z, (*data).Vx, (*data).Vy,
			(*data).Vz };
	for (int i = 0; i < 6; ++i)
		values[0][i] = source[i];
	K = (*data).aerodynamic_quality;
}

double dx(double t, double *params);
double dy(double t, double *params);
double dz(double t, double *params);
double dVx(double t, double *par);
double dVy(double t, double *par);
double dVz(double t, double *par);
double r(double *p);
double V(double *p);
double h(double *p);
double li(double *p, int number);
double mi(double *p, int number);
double p_(double *params);
int higher_than_5km(double *p);

/* унифицированная функция решения системы ДУ */
int odeCompute(
		int (*odeFunc)(int count, double (*u[])(double t, double *params),
				double *t, int steps, double delta_t, double **values,
				int (*condition)(double *params)), int steps, double *t,
		double **values) {
	double (*de[])(double t, double params[])= {dx,dy,dz,dVx,dVy,dVz };
	return odeFunc(6, de, t, steps, t[1] - t[0], values, higher_than_5km);
}

double n = 398600.0;    // гравитационная постоянная Земли, км3/с2
double cxa = 1.3;    // аэродинамический коэффициент силы лобового сопротивления
double Smid = 15e-6;     // площадь миделя, км2
double m = 8000;      // масса ЛА, кг
double w = 7.292115855e-5;  // угловая скорость вращения Земли, с-1
double Rz = 6371.0; // средний радиус Земли, км
double alpha_szh = 0.003352824419; // коэффициент сжатия земного эллипсоида
double g0 = 9.80665e-3; // ускорение свободного падения на уровне моря, км/с2

/* перевод угла из градусов в радианы */
double d2r(double deg) {
	return deg * M_PI / 180.0;
}
/* перевод угла из радиан в градусы */
double r2d(double rad) {
	return rad * 180.0 / M_PI;
}

/* правая часть ДУ */
double dx(double t, double *params) {
	return params[3];
}
double dy(double t, double *params) {
	return params[4];
}
double dz(double t, double *params) {
	return params[5];
}
double getGamma(double *p); // угол крена, зависящий от высоты по программе
double dVx(double t, double *par) {
	return -n * par[0] / pow(r(par), 3.0)
			- cxa * (Smid / (2 * m)) * p_(par) * V(par) * par[3]
			+ K * cxa * (Smid / (2 * m)) * p_(par) * V(par)*V(par)
					* (mi(par, 0) * cos(d2r(getGamma(par)))
							+ li(par, 0) * sin(d2r(getGamma(par))))
			+ par[0] * (w * w) + 2 * w * par[4];
}
double dVy(double t, double *par) {
	return -n * par[1] / pow(r(par), 3.0)
			- cxa * (Smid / (2 * m)) * p_(par) * V(par) * par[4]
			+ K * cxa * (Smid / (2 * m)) * p_(par) * V(par)*V(par)
					* (mi(par, 1) * cos(d2r(getGamma(par)))
							+ li(par, 1) * sin(d2r(getGamma(par))))
			+ par[1] * (w * w) - 2 * w * par[3];
}
double dVz(double t, double *par) {
	return -n * par[2] / pow(r(par), 3.0)
			- cxa * (Smid / (2 * m)) * p_(par) * V(par) * par[5]
			+ K * cxa * (Smid / (2 * m)) * p_(par) * V(par)*V(par)
					* (mi(par, 2) * cos(d2r(getGamma(par)))
							+ li(par, 2) * sin(d2r(getGamma(par))));
}

/* расчёт ведётся до достижения высоты 5 км */
int higher_than_5km(double *p) {
	return h(p) >= 5.0;
}

/* вспомогательные функции */

/* модуль радиуса-вектора центра масс */
double r(double *p) {
	return sqrt(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]);
}
/* модуль вектора скорости */
double V(double *p) {
	return sqrt(p[3]*p[3] + p[4]*p[4] + p[5]*p[5]);
}
void vectorMultiplication(double a[], double b[], double result[]) {
	result[0] = a[1] * b[2] - a[2] * b[1];
	result[1] = a[2] * b[0] - a[0] * b[2];
	result[2] = a[0] * b[1] - a[1] * b[0];
}
/* возвращает один из компонентов единичного вектора-нормали к местной вертикальной плоскости */
double li(double *p, int number) {
	double v[] = { p[3], p[4], p[5] };
	double r[] = { p[0], p[1], p[2] };
	double res[3] = { 0 };
	vectorMultiplication(v, r, res);
	return res[number] / fabs(res[number]);
}
/* возвращает один из компонентов единичного вектора, лежащего в местной
 * вертикальной плоскости и перпендикулярного вектору скорости */
double mi(double *p, int number) {
	double v[] = { p[3], p[4], p[5] };
	double r[] = { p[0], p[1], p[2] };
	double res[3] = { 0 }, res1[3] = { 0 };
	vectorMultiplication(v, r, res);
	for (int i = 0; i < 3; ++i) {
		res[i] = res[i] / fabs(res[i]);
	}
	vectorMultiplication(res, v, res1);
	return res1[number] / fabs(res1[number]);
}
/* Возвращает высоту для указанного местоположения, в км */
double h(double *p) {
	return sqrt(p[0]*p[0] + p[1]*p[1] + p[2]*p[2])
			- Rz * (1-alpha_szh*p[2]*p[2] / (p[0]*p[0] + p[1]*p[1] + p[2]*p[2]));
}
/* Возвращает плотность атмосферы для указанного местоположения, кг/км3 */
double p_(double *params) {
	return 1e9 * p(params);
}
/* Возвращает широту, град */
double phi(double *p) {
	return r2d(asin(p[2] / sqrt(pow(pow(1 - alpha_szh, 2.0) * sqrt(p[0]*p[0] + p[1]*p[1]),2.0) + p[2]*p[2])));
}
/* Возвращает долготу, град */
double lambda(double *p) {
	return r2d(atan2(p[1], p[0]));
}
/* Возвращает угол крена для текущего местоположения, град */
double getGamma(double *p) {
	double H = h(p);
	if (H > 55.0)
		return input_data.angle_55;
	else if (H >= 45.0)
		return input_data.angle_55_45;
	else
		return input_data.angle_45;
}
/* Отклонение на Север */
double deltaNorth(double phi, double phi_i) {
	return d2r(phi_i - phi) * Rz;
}
/* Отклонение на Восток */
double deltaEast(double lambda, double lambda_i) {
	return d2r(lambda_i - lambda) * Rz * cos(d2r(lambda));
}
/* Вычисляет значение перегрузки для текущего местоположения */
double overload(double *p) {
	return cxa * sqrt(1 + K * K) * p_(p) * V(p) * V(p) * Smid / (2 * m * g0);
}
/* Возвращает максимальное значение в массиве */
double max(double *values, int count) {
	double result = values[0];
	for (int i = 1; i < count; ++i)
		if (values[i] > result)
			result = values[i];
	return result;
}
