/*
 * lcd.c
 *
 * Created: 13/02/2019 10:56:17
 *  Author: Bou
 */ 
#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>

void lcd_writeChar( unsigned char dat );

void lcd_command( unsigned char command){
	PORTC = command & 0xF0;
	PORTC |= 0x08;
	
	_delay_ms(1);
	PORTC = 0x04;
	
	PORTC = (command & 0x0F) << 4;
	PORTC |= 0x08;
	
	_delay_ms(1);
	PORTC = 0x00;
};

void init(){
	DDRC = 0xFF;
	// return home
	lcd_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	lcd_command( 0x28 );
	// display: on, cursor off, blinking off
	lcd_command( 0x0C );
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
	
	//lcd_command();
}

void lcd_writeChar( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}


