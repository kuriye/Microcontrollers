
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

/**
 * \brief Initializes MatrixCharacters, creates data for each letter so it can be printed on the Led Matrix
 * 
 * \param void
 * 
 * \return void
 */
void MatrixCharactersInit(void);


/**
 * \brief Gets the data for on the Led Matrix for a specific letter
 * 
 * \param letter - the letter you want the data from
 * 
 * \return char* - data for displaying in the Led Matrix
 */
char* MatrixCharactersGet(char letter);

#endif /*MATRIX_CHARACTERS_H_*/