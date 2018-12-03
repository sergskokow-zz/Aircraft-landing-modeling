/*
 * inputData.h
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#ifndef INPUTDATA_H_
#define INPUTDATA_H_

struct inputData {
	/* компоненты радиуса-вектора центра масс и вектора скорости */
	double x, y, z, Vx, Vy, Vz;
	/* программа изменения угла крена */
	double angle_55, angle_55_45, angle_45;
	/* величина аэродинамического качества */
	double aerodynamic_quality;
	/* время и шаг моделирования */
	double time, step;
};

int readData(char *fileName, struct inputData *data);

#endif /* INPUTDATA_H_ */
