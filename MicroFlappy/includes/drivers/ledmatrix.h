/*
 * letmatrix.h
 *
 * Author: Carlos Cadel
 */ 

#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

// Defines for the size of the game field
#define FIELD_WIDTH		8	
#define FIELD_HEIGHT	8

void matrix_init(void);
void matrix_clear(void);
void matrix_fill(void);
void matrix_draw_game_field(int [FIELD_WIDTH][FIELD_HEIGHT]);

#endif /* LEDMATRIX_H_ */