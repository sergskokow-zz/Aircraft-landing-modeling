/*
 * html.h
 *
 *  Created on: 28 нояб. 2018 г.
 *      Author: sergskokow
 */

#ifndef HTML_H_
#define HTML_H_

int createHTML(char *fileName);
void writeTable(int rows, int columns, double table[rows][columns], char *title,
		char *columnNames[columns]);
void closeHTML();

#endif /* HTML_H_ */
