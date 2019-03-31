/*
 * scroller.c
 *
 * Author: Carlos Cadel
 */ 
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "drivers/ledmatrix.h"

#include "logic/matrixCharacters.h"
#include "logic/scroller.h"

char TextToWrite[TEXT_MAX_SIZE][HT16K33_MAX_ROWS];
char FieldToDraw[HT16K33_MAX_ROWS];

uint8_t leftShift = 0;
int8_t ScrollStringIndex = 0;
uint8_t textSize = 0;

uint8_t scrollerUpdateCounter = 0;
uint8_t scrollerUpdateSpeed = 0;

void ScrollerInit()
{
	MatrixInit();
	MatrixClear();
	MatrixCharactersInit();
}

void ScrollerSetText(char text[TEXT_MAX_SIZE])
{
	leftShift = 0;
	ScrollStringIndex = 0;
	textSize = strlen(text);
	
	for(int i = 0; text[i] != '\0'; i++) //all text to upper case
	{
		text[i] = toupper(text[i]);
	}
	
	for(int i = 0; text[i] != '\0'; i++) //Iterate through chars from string
	{
		char letter = text[i];
		memcpy(TextToWrite[i], MatrixCharactersGet(letter), sizeof(TextToWrite[i]));
	}
	
	MatrixDrawField(TextToWrite[0]);
}

void ScrollerSetSpeed(uint8_t speed)
{
	//if(speed < 50)
	//	speed = 50;
	//if (speed > 150)
	//	speed = 150;
	
	scrollerUpdateSpeed = speed;
}

void ScrollerUpdate()
{	
	if(scrollerUpdateCounter >= scrollerUpdateSpeed)
	{
		scrollerUpdateCounter = 0;
		
		for (int y = 0; y < HT16K33_MAX_ROWS; y++) //Init field to draw
		{
			char row = 0x00;
		
			if(ScrollStringIndex > -1)
			row |= TextToWrite[ScrollStringIndex][y] << leftShift;
		
			if(ScrollStringIndex+1 < TEXT_MAX_SIZE)
			row |= TextToWrite[ScrollStringIndex+1][y] >> (HT16K33_MAX_ROWS - leftShift);
		
			FieldToDraw[y] = row & 0xff;
		}
	
		MatrixDrawField(FieldToDraw); //Draws field
	
		if(leftShift >= 8) //Changes when another letter is coming up
		{
			leftShift = 0;
			ScrollStringIndex++;
		
			if(ScrollStringIndex >= textSize) // Reached last character, show blank first
			ScrollStringIndex = -1;
		}
	
		leftShift++;
	}
	
	scrollerUpdateCounter++;
}