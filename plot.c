/*
 * plot.c
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#include <stdio.h>

int currentWindowNumber = 0;

/* выбор окна по номеру */
void selectWindow(FILE *gpipe, int number) {
	fprintf(gpipe, "set term wxt %d persist\n", number);
}

/* переход в новое окно */
void figure(FILE *gpipe) {
	selectWindow(gpipe, ++currentWindowNumber);
}

/* нарисовать график с заданным названием и подписями осей */
void plot(FILE *gpipe, double *x, double *y, int count, char title[],
		char lineName[], char xlabel[], char ylabel[]) {
	if (!gpipe)
		return;
	if (title != NULL)
		fprintf(gpipe, "set title \"%s\"\n", title);
	if (xlabel != NULL)
		fprintf(gpipe, "set xlabel \"%s\"\n", xlabel);
	if (ylabel != NULL)
		fprintf(gpipe, "set ylabel \"%s\"\n", ylabel);
	fprintf(gpipe, "%s\n", "set grid xtics ytics mxtics mytics");

	fprintf(gpipe, "%s\n", "$DATA << EOD");
	for (int i = 0; i < count; ++i)
		fprintf(gpipe, "%g %g\n", x[i], y[i]);
	fprintf(gpipe, "%s\n", "EOD");
	fprintf(gpipe, "%s\n",
			"plot $DATA using 1:2 with lines lt rgb \"blue\" notitle");
}

/* нарисовать точки к существующему графику */
void dots(FILE *gpipe, int count, double *x, double *y, char **label) {
	if (label != NULL) {
		for (int i = 0; i < count; ++i) {
			fprintf(gpipe, "set label \"%s\" at %g,%g\n", label[i],
					x[i] + 0.005, y[i] - 0.005);
		};
	}
	fprintf(gpipe, "%s\n", "$POINTS << EOP");
	for (int i = 0; i < count; ++i) {
		fprintf(gpipe, "%g %g\n", x[i], y[i]);
	}
	fprintf(gpipe, "%s\n", "EOP");
	fprintf(gpipe, "%s\n",
			"plot $DATA using 1:2 with lines lt rgb \"blue\" notitle, $POINTS using 1:2 with points pt 7 ps 1 lt rgb \"red\" notitle");

}

void pause(FILE *gpipe) {
	fprintf(gpipe, "%s\n", "pause mouse keypress");
}
/* сброс меток */
void reset(FILE *gpipe) {
	fprintf(gpipe, "%s\n", "reset");
}
