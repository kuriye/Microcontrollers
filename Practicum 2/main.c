/*
 * Practicum 2.c
 *
 * Created: 2/6/2019 10:24:18 AM
 * Author : paulh
 */ 
#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR( INT1_vect )
{
	if(PORTA >= 0x80) {
		PORTA = 0x01;
	} else {
		PORTA = PORTA << 1;
	}
	_delay_ms(100);
}

ISR( INT2_vect )
{
	if(PORTA > 0x01) {
		PORTA = PORTA >> 1;
	} else {
		PORTA = 0x80;
	}
	_delay_ms(100);
}

int main( void )
{
	// Init I/O
	DDRA = 0xFF;
	DDRD = 0xF0;			// PORTD(3:0) input

	// Init Interrupt hardware
	EICRA |= 0x3C;			// 0b0011 1100
	EIMSK |= 0x06;			// 0b0000 0110
	
	// Enable global interrupt system
	sei();				

	PORTA = 0x01;

	while (1) {
		
	}

	return 1;
}
