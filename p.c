/*
 * p.c
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#include <math.h>
extern double h(double p[]);

/* Расчёт плотности атмосферы для указанного местоположения, кг/м3 */
double p(double params[]) {
	double Ryc = 6356.766e3, g0 = 9.80665, R = 287.05287;
	double H = 1e3*h(params);
	if (H < 0.0)
		return 0.0;
	double F = H * Ryc / (H + Ryc);
	/* таблица плотности атмосферы, температуры воздуха
	 * и градиента температуры в слое в зависимости от высоты полёта */
	double Table[12][4] = {
		/*   %Ф*[м]     Tм*[К]  aм* [К/м]  p/g0[кг*с2/м4] */
			{ 0.0,      288.15, -0.0065, 1.24915236E-1 },
			{ 11.0e3,   216.65, 0.0,     3.71093080E-2 },
			{ 20.0e3,   216.65, 0.0010,  8.97702069E-3 },
			{ 32.0e3,   228.65, 0.0028,  1.34856449E-3 },
			{ 47.0e3,   270.65, 0.0,     1.45566528E-4 },
			{ 51.0e3,   270.65, -0.0028, 8.78587489E-5 },
			{ 71.0e3,   214.65, -0.0020, 6.54764879E-6 },
			{ 80.0e3,   196.65, -0.0020, 1.60099524E-6 },
			{ 85.0e3,   186.65, 0.0,     6.91423676E-7 },
			{ 94.0e3,   186.65, 0.0030,  1.33266712E-7 },
			{ 102.45e3, 212.00, 0.0110,  2.74594280E-8 },
			{ 117.77e3, 380.60, 0.0078,  2.48852564E-9 }
	};

	/* выбор слоя по текущей высоте */
	int si = 0;
	for(int i=0;i<12;++i)
		if(H>Table[i][0])
			si = i;

	if(Table[si][2]==0.0)
		return Table[si][3]*g0*exp((g0/R)*(Table[si][0]-F)/Table[si][1]);
	else
	{
		double Tm = Table[si][1] + Table[si][2]*(F-Table[si][0]);
		return Table[si][3]*g0*exp((1+(g0/R)*(1/Table[si][2]))*log(Table[si][1]/Tm));
	}
}