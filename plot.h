/*
 * plot.h
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#ifndef PLOT_H_
#define PLOT_H_

void plot(FILE *gpipe, double *x, double *y, int count, char title[],
		char lineName[], char xlabel[], char ylabel[]);
void figure(FILE *gpipe);
void selectWindow(FILE *gpipe, int number);
void dots(FILE *gpipe, int count, double *x, double *y, char **label);
void pause(FILE *gpipe);
void reset(FILE *gpipe);

#endif /* PLOT_H_ */
