/*
 * letmatrix.h
 *
 * Author: Carlos Cadel
 */ 

#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

#define HT16K33_MAX_ROWS 8

/**
 * \brief Init the matrix display
 *  
 *
 * \return void
 */
void MatrixInit(void);

/**
 * \brief - Clears the entire display
 * 
 * 
 * \return void
 */
void MatrixClear(void);

/**
 * \brief - Fills all the dots on the display
 * 
 * 
 * \return void
 */
void MatrixFill(void);

/**
 * \brief - draws an entiire field of data
 * 
 * \param data - the field it needs to draw
 * 
 * \return void
 */
void MatrixDrawField(char data[HT16K33_MAX_ROWS]);

/**
 * \brief - draws a row of data on the screen
 * 
 * \param row - the row it needs to draw
 * \param data - the data for the row to draw on
 * 
 * \return void
 */
void MatrixDrawRow(int row, int data);


#endif /* LEDMATRIX_H_ */