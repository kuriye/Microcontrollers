
/*
 * matrixCharacters.c
 *
 * Created: 28/03/2019 09:52:39
 *  Author: Carlos Cadel
 */ 

#include "logic/matrixCharacters.h"

MatrixCharachter alphabet[MATRIX_CHARACTER_ALPHABET_LENGTH];

void MatrixCharactersInit(void)
{
	alphabet[0] = (MatrixCharachter) {'A', {
		0b00000000,
		0b00111100,
		0b01100110,
		0b01100110,
		0b01111110,
		0b01100110,
		0b01100110,
		0b01100110
	}};
	
	alphabet[1] = (MatrixCharachter) {'B', {
		0b00000000,
		0b01111100,
		0b01100110,
		0b01100110,
		0b01111100,
		0b01100110,
		0b01100110,
		0b01111100
	}};
}

char* MatrixCharactersGet(char letter)
{
	int i;
	for(i = 0; i < MATRIX_CHARACTER_ALPHABET_LENGTH; i++)
	{
		if(alphabet[i].letter == letter)
		{
			return alphabet[i].data;
		}
	}
	
	return "";
}
