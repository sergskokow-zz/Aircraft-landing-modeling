/*
 * de.h
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#ifndef DE_H_
#define DE_H_

void prepareValues(double t_begin, double t_end, int steps, double delta_t,
		double *t, double **values, struct inputData *data);
int ode1(int count, double (*u[])(double t, double *params), double *t,
		int steps, double delta_t, double **values,
		int (*condition)(double *params));

int odeCompute(
		int (*odeFunc)(int count, double (*u[])(double t, double *params),
				double *t, int steps, double delta_t, double **values,
				int (*condition)(double *params)), int steps, double *t,
		double **values);

double h(double *p);
double phi(double *p);
double lambda(double *p);
double deltaNorth(double phi, double phi_i);
double deltaEast(double lambda, double lambda_i);
double overload(double *p);
double max(double *values, int count);
double getGamma(double *p);
double V(double *p);

#endif /* DE_H_ */
