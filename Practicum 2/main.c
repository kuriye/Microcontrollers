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


int digit = 0;

const unsigned char
NUMBERS[10] =
{
	// dPgfedcba
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111, // 9
	0b01110111, // A
	0b01110100, // B
	0b00111001, // C
	0b01011110, // D
	0b01101011, // E
};

void display(int digit){
	if( 0 <= digit <= 15){
		PORTA = NUMBERS[digit];
	}
	else {
		PORTA = NUMBERS[15];
	}

}

ISR( INT1_vect )
{
	digit++;
	display(digit);
	_delay_ms(100);
}

ISR( INT2_vect )
{
	digit--;
	display(digit);
	_delay_ms(100);
}




int main( void )
{
	// Init I/O
	DDRA = 0xFF;
	DDRD = 0xFF;			// PORTD(3:0) input

	// Init Interrupt hardware
	EICRA |= 0x3C;			// 0b0011 1100
	EIMSK |= 0x06;			// 0b0000 0110
	
	// Enable global interrupt system
	sei();				


	while (1) {
		if(PIND & 0x03) {
			//digit =0;
		}
	}

	return 1;
}



