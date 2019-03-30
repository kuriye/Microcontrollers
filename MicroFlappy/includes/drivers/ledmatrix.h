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
 * \brief - draws an entire field of data
 * 
 * \param data - the field it needs to draw
 * 
 * \return void
 */
void MatrixDrawField(char data[HT16K33_MAX_ROWS]);

/**
 * \brief - draws a row of data on the screen
 * 
 * \param row - the row it needs to draw at
 * \param data - the data for the row to draw on
 * 
 * \return void
 */
void MatrixDrawRow(int row, int data);

/**
 * \brief - scrolls the field to the left
 * 
 * 
 * \return void
 */
void MatrixScrollField(void);

/**
 * \brief -  draws a string to the display
 * 
 * \param text - the string that needs to be drawn
 * 
 * \return void
 */
void MatrixDrawString(char* text);


/**
 * \brief - to scroll the string over the display
 * 
 * 
 * \return void
 */
void MatrixScrollString(void);

#endif /* LEDMATRIX_H_ */