
/*
 * matrixCharacters.h
 *
 * Created: 28/03/2019 10:15:26
 *  Author: Carlos Cadel
 */ 

#ifndef MATRIX_CHARACTERS_H_
#define MATRIX_CHARACTERS_H_

#define MATRIX_CHARACTER_LENGTH				8
#define MATRIX_CHARACTER_ALPHABET_LENGTH	27

typedef struct MatrixCharachter {
	char letter;
	char data[MATRIX_CHARACTER_LENGTH];
}MatrixCharachter;

void MatrixCharactersInit(void);
char* MatrixCharactersGet(char letter);

#endif /*MATRIX_CHARACTERS_H_*/