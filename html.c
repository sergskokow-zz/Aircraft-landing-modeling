/*
 * html.c
 *
 *  Created on: 28 нояб. 2018 г.
 *      Author: sergskokow
 */

#include <stdio.h>

FILE *html;

/* создание файла HTML для сохранения таблиц */
int createHTML(char *fileName) {
	html = fopen(fileName, "w");
	if (html == NULL)
		return -1;
	fprintf(html, "%s\n%s\n", "<!DOCTYPE html>", "<html>");
	fprintf(html, "%s\n",
			"<head><META charset=\"UTF-8\"/><style>table{border:1px solid black;}</style></head>");
	fprintf(html, "%s\n", "<body>");
	return 0;
}

/* запись таблицы указанного размера */
void writeTable(int rows, int columns, double table[rows][columns], char *title,
		char *columnNames[columns]) {
	fprintf(html, "%s\n", title);
	fprintf(html, "%s\n", "<table>");
	fprintf(html, "%s", "<tr>");
	for (int i = 0; i < columns; ++i)
		fprintf(html, "<th>%s</th>", columnNames[i]);
	fprintf(html, "%s\n", "</tr>");
	for (int m = 0; m < rows; ++m) {
		fprintf(html, "%s", "<tr>");
		for (int n = 0; n < columns; ++n)
			fprintf(html, "<td>%g</td>", table[m][n]);
		fprintf(html, "%s\n", "</tr>");
	}
	fprintf(html, "%s\n", "</table>");
}

void closeHTML() {
	fprintf(html, "%s\n%s", "</body>", "</html>");
	fclose(html);
}
