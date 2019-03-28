/*
 * ledmatrix.c
 *
 * Author: Carlos Cadel
 */ 

#include <avr/io.h>

#include "drivers/ledmatrix.h"
#include "drivers/i2c.h"
#include "logic/matrixCharacters.h"
#include <string.h>

#define HT16K33_ADDR			0xE0
#define HT16K33_CMD_ON			0x21
#define HT16K33_CMD_ALL_OUTPUT	0xA0

#define HT16K33_CMD_DIM			0xE3
#define HT16K33_CMD_DIM_OFF		0x00
#define HT16K33_CMD_DIM_2H		0x01
#define HT16K33_CMD_DIM_1H		0x10
#define HT16K33_CMD_DIM_05H		0x11

#define D0_I2C_ADDR	((0x70 + 0) << 1)

#define TEXT_TO_WRITE_MAX_SIZE	255

char TextToWrite[TEXT_TO_WRITE_MAX_SIZE][HT16K33_MAX_ROWS];
char FieldToDraw[HT16K33_MAX_ROWS];
uint8_t leftShift = 0;
int8_t ScrollStringIndex = 0;
uint8_t textSize = 0;

void MatrixShiftData(int *data);

// Initializes both of the matrix displays
void MatrixInit()
{	
	MatrixCharactersInit();
	
	I2CStart();
	I2CSelect(HT16K33_ADDR, I2C_SEL_MODE_W);
	I2CWrite(HT16K33_CMD_ON); // Internal osc on 00100001
	I2CStop();
	
	I2CStart();
	I2CSelect(HT16K33_ADDR, I2C_SEL_MODE_W);
	I2CWrite(HT16K33_CMD_ALL_OUTPUT); // HT16K33 pins all output
	I2CStop();
	
	I2CStart();
	I2CSelect(HT16K33_ADDR, I2C_SEL_MODE_W);
	I2CWrite(HT16K33_CMD_DIM); // Dimming 4/16 duty cycle
	I2CStop();
	
	I2CStart();
	I2CSelect(HT16K33_ADDR, I2C_SEL_MODE_W);
	I2CWrite(0x81); // Display OFF - Blink On
	I2CStop();
}

void MatrixClear()
{
	for (int y = 0; y < HT16K33_MAX_ROWS; y++)
	{
		MatrixDrawRow(y, 0x00);
	}
}

void MatrixFill()
{
	for (int y = 0; y < HT16K33_MAX_ROWS; y++)
	{
		MatrixDrawRow(y, 0xFF);
	}
}

void MatrixDrawField(char data[HT16K33_MAX_ROWS])
{
	for (int y = 0; y < HT16K33_MAX_ROWS; y++)
	{
		MatrixDrawRow(HT16K33_MAX_ROWS-1-y, data[y]);
	}
}

void MatrixDrawRow(int row, int data)
{
	MatrixShiftData(&data);
	
	I2CStart();
	I2CSelect(HT16K33_ADDR, I2C_SEL_MODE_W);
	I2CWrite(row * 2);
	I2CWrite(data);
	I2CStop();
}

void MatrixShiftData(int *data)
{
	if (*data & 1)	// If bit 1 is set, shift everything to the right and set bit 8 to 1
		*data = (*data - 1) / 2 + (1 << 7);
	else			// If bit 1 is not set, just shift everything to the right
		*data /= 2;
}

void MatrixDrawString(char text[255])
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

void MatrixScrollString(void)
{	
	for (int y = 0; y < HT16K33_MAX_ROWS; y++) //Init field to draw
	{
		char row = 0x00;
		
		if(ScrollStringIndex > -1)
			row |= TextToWrite[ScrollStringIndex][y] << leftShift;
		
		if(ScrollStringIndex+1 < TEXT_TO_WRITE_MAX_SIZE) 
			row |= TextToWrite[ScrollStringIndex+1][y] >> (HT16K33_MAX_ROWS - leftShift);
		
		char finalrow = row & 0xff;
		FieldToDraw[y] = finalrow;
	}
	MatrixDrawField(FieldToDraw); //Draws field
	
	if(leftShift >= 8) //Changes when another letter is coming up
	{
		leftShift = 0;
		ScrollStringIndex++;
		
		if(ScrollStringIndex >= textSize)
			ScrollStringIndex = -1;
	}
	
	leftShift++;
}
