/*
 * lcd.c
 *
 * Created: 20/03/2019 09:11:02
 *  Author: Bou's Laptop
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>
#include "drivers/lcd.h"

void LcdCommand( unsigned char command)
{
	PORTC = command & 0xF0;
	PORTC |= 0x08;
	
	_delay_ms(2);
	PORTC = 0x04;
	
	PORTC = (command & 0x0F) << 4;
	PORTC |= 0x08;
	
	_delay_ms(2);
	PORTC = 0x00;
};

void lcd_writeChar(unsigned char byte)
{
	PORTC = byte & 0xF0;
	PORTC = PORTC | 0x0C;

	_delay_ms(2);
	PORTC = 0x04;
	PORTC = (byte & 0x0F) << 4;
	PORTC = PORTC | 0x0C;

	_delay_ms(2);
	PORTC = 0x00;
}

void LcdInit()
{
	DDRC = 0xFF;
	PORTC = 0x00;

	// return home
	LcdCommand( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	LcdCommand( 0x28 );
	// display: on, cursor off, blinking off
	LcdCommand( 0x0E );
	// entry mode: cursor to right, no shift
	LcdCommand( 0x06 );
	// RAM adress: 0, first position, line 1
	LcdCommand( 0x80 );
}

void LcdDisplayText(char *str)
{
	for(; *str; str++){
		lcd_writeChar(*str);
	}
}

void LcdSetCursor(int position)
{
	
	if(position >= 16)
	{
		LcdCommand(0xc0 + (position - 16));
	}
	else
	{
		LcdCommand(0x80 + position);
	}
}void LcdClear(){	LcdCommand(0x01);}