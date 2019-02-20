/*
 * lcd.c
 *
 * Created: 13/02/2019 10:56:17
 *  Author: Bou
 */ 
#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>

void lcd_command( unsigned char command){
	PORTC = command & 0xF0;
	PORTC |= 0x08;
	
	_delay_ms(25);
	PORTC = 0x04;
	
	PORTC = (command & 0x0F) << 4;
	PORTC |= 0x08;
	
	_delay_ms(25);
	PORTC = 0x00;
};

void lcd_writeChar(unsigned char byte)
{
	PORTC = byte & 0xF0;
	PORTC = PORTC | 0x0C;

	_delay_ms(1);
	PORTC = 0x04;
	PORTC = (byte & 0x0F) << 4;
	PORTC = PORTC | 0x0C;

	_delay_ms(1);
	PORTC = 0x00;
}

void init(){
	DDRC = 0xFF;
	PORTC = 0x00;

	// return home
	lcd_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	lcd_command( 0x28 );
	// display: on, cursor off, blinking off
	lcd_command( 0x0E );
	// entry mode: cursor to right, no shift
	lcd_command( 0x06 );
	// RAM adress: 0, first position, line 1
	lcd_command( 0x80 );
}

void display_text(char *str){
	for(; *str; str++){
		lcd_writeChar(*str);
	}
}

void set_cursor(int position){
	
	if(position >= 16)
	{
		lcd_command(0xc0 + (position - 16));
	}
	else
	{
		lcd_command(0x80 + position);
	}
}void clear(){	lcd_command(0x01);}


