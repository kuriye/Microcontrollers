
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
	
	alphabet[2] = (MatrixCharachter) {'C', {
		0b00000000,
		0b00111100,
		0b01100110,
		0b01100000,
		0b01100000,
		0b01100000,
		0b01100110,
		0b00111100
	}};
	
	alphabet[3] = (MatrixCharachter) {'D', {
		0b00000000,
		0b01111100,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01111100
	}};
	
	alphabet[4] = (MatrixCharachter) {'E', {
		0b00000000,
		0b01111110,
		0b01100000,
		0b01100000,
		0b01111100,
		0b01100000,
		0b01100000,
		0b01111110
	}};
	
	alphabet[5] = (MatrixCharachter) {'F', {
		0b00000000,
		0b01111110,
		0b01100000,
		0b01100000,
		0b01111100,
		0b01100000,
		0b01100000,
		0b01100000
	}};
	
	alphabet[6] = (MatrixCharachter) {'G', {
		0b00000000,
		0b00111100,
		0b01100110,
		0b01100000,
		0b01100000,
		0b01101110,
		0b01100110,
		0b00111100
	}};
	
	alphabet[7] = (MatrixCharachter) {'H', {
		0b00000000,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01111110,
		0b01100110,
		0b01100110,
		0b01100110
	}};
	
	alphabet[8] = (MatrixCharachter) {'I', {
		0b00000000,
		0b00111100,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00111100
	}};
	
	alphabet[9] = (MatrixCharachter) {'J', {
		0b00000000,
		0b00011110,
		0b00001100,
		0b00001100,
		0b00001100,
		0b01101100,
		0b01101100,
		0b00111000
	}};
	
	alphabet[10] = (MatrixCharachter) {'K', {
		0b00000000,
		0b01100110,
		0b01101100,
		0b01111000,
		0b01110000,
		0b01111000,
		0b01101100,
		0b01100110
	}};
	
	alphabet[11] = (MatrixCharachter) {'L', {
		0b00000000,
		0b01100000,
		0b01100000,
		0b01100000,
		0b01100000,
		0b01100000,
		0b01100000,
		0b01111110
	}};
	
	alphabet[12] = (MatrixCharachter) {'M', {
		0b00000000,
		0b01100011,
		0b01110111,
		0b01111111,
		0b01101011,
		0b01100011,
		0b01100011,
		0b01100011
	}};
	
	alphabet[13] = (MatrixCharachter) {'N', {
		0b00000000,
		0b01100011,
		0b01110011,
		0b01111011,
		0b01101111,
		0b01100111,
		0b01100011,
		0b01100011
	}};
	
	alphabet[14] = (MatrixCharachter) {'O', {
		0b00000000,
		0b00111100,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b00111100
	}};
	
	alphabet[15] = (MatrixCharachter) {'P', {
		0b00000000,
		0b01111100,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01111100,
		0b01100000,
		0b01100000
	}};
	
	alphabet[16] = (MatrixCharachter) {'Q', {
		0b00000000,
		0b00111100,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01101110,
		0b00111100,
		0b00000110
	}};
	
	alphabet[17] = (MatrixCharachter) {'R', {
		0b00000000,
		0b01111100,
		0b01100110,
		0b01100110,
		0b01111100,
		0b01111000,
		0b01101100,
		0b01100110
	}};
	
	alphabet[18] = (MatrixCharachter) {'S', {
		0b00000000,
		0b00111100,
		0b01100110,
		0b01100000,
		0b00111100,
		0b00000110,
		0b01100110,
		0b00111100
	}};
	
	alphabet[19] = (MatrixCharachter) {'T', {
		0b00000000,
		0b01111110,
		0b01011010,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00011000
	}};
	
	alphabet[20] = (MatrixCharachter) {'U', {
		0b00000000,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b00111110
	}};
	
	alphabet[21] = (MatrixCharachter) {'V', {
		0b00000000,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b01100110,
		0b00111100,
		0b00011000
	}};
	
	alphabet[22] = (MatrixCharachter) {'W', {
		0b00000000,
		0b01100011,
		0b01100011,
		0b01100011,
		0b01101011,
		0b01111111,
		0b01110111,
		0b01100011
	}};
	
	alphabet[23] = (MatrixCharachter) {'X', {
		0b00000000,
		0b01100011,
		0b01100011,
		0b00110110,
		0b00011100,
		0b00110110,
		0b01100011,
		0b01100011
	}};
	
	alphabet[24] = (MatrixCharachter) {'Y', {
		0b00000000,
		0b01100110,
		0b01100110,
		0b01100110,
		0b00111100,
		0b00011000,
		0b00011000,
		0b00011000
	}};
	
	alphabet[25] = (MatrixCharachter) {'Z', {
		0b00000000,
		0b01111110,
		0b00000110,
		0b00001100,
		0b00011000,
		0b00110000,
		0b01100000,
		0b01111110
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
