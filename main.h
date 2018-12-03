/*
 * main.h
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#include "inputData.h"
#include "de.h"
#include "plot.h"
#include "html.h"

int computeMain(struct inputData *inputData, double **time, double **H,
		double ***values, double **PHI, double **LAMBDA, double **G0);
void computeAngles(int angleCount, double angle[angleCount], double *H,
		double targetH, double **values, int lastValueIndex, double *PHI,
		double *LAMBDA, double DeltaNorth[], double DeltaEast[], double N[]);
int getHeightIndex(double *H, int count, double target);

#define HEIGHT_COUNT 11
#define COLUMN_COUNT 4
#define ANGLE_COUNT 15
#define TARGET_HEIGHT_COUNT 9

#endif /* MAIN_H_ */
