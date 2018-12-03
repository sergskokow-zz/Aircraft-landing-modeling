/*
 * inputData.c
 *
 *  Created on: 21 нояб. 2018 г.
 *      Author: sergskokow
 */

#include "cJSON/cJSON.h" /* https://github.com/DaveGamble/cJSON */
#include "inputData.h"
#include <stdio.h>
#include <stdlib.h>

int readData(char *fileName, struct inputData *data) {
	FILE *fp = fopen(fileName, "r"); // открываем файл
	if (fp == NULL)
		return -1;
	fseek(fp, 0, SEEK_END);
	long lSize = ftell(fp); // расчёт длины файла
	rewind(fp);
	char * buffer = (char*) malloc(sizeof(char) * lSize);
	if (buffer == NULL)
		return -2;
	fread(buffer, 1, lSize, fp); // чтение файла целиком
	fclose(fp);

	cJSON *jsonData = cJSON_Parse(buffer); // парсим JSON-файл
	if (jsonData == NULL)
		return -3;

	/* массив указателей для более краткой записи */
	double *destination[] = { &((*data).x), &((*data).y), &((*data).z),
			&((*data).Vx), &((*data).Vy), &((*data).Vz), &((*data).angle_55),
			&((*data).angle_55_45), &((*data).angle_45),
			&((*data).aerodynamic_quality), &((*data).time), &((*data).step) };
	cJSON *param, *param1;
	int i = 0;
	cJSON_ArrayForEach(param, jsonData)
	/* читаем все значения подряд */
	{
		if (param->child != NULL) {
			cJSON_ArrayForEach(param1, param)
			{
				*(destination[i]) = param1->valuedouble;
				++i;
			}
		} else {
			*(destination[i]) = param->valuedouble;
			++i;
		}
	}
	cJSON_Delete(jsonData);
	return 0;
}
