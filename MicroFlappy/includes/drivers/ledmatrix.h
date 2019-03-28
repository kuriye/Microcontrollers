/*
 * letmatrix.h
 *
 * Author: Carlos Cadel
 */ 

#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

#define HT16K33_MAX_ROWS 8

void MatrixInit(void);
void MatrixClear(void);
void MatrixFill(void);
void MatrixDrawField(char data[HT16K33_MAX_ROWS]);
void MatrixDrawRow(int row, int data);
void MatrixDrawString(char* text);
void MatrixScrollString(void);

#endif /* LEDMATRIX_H_ */