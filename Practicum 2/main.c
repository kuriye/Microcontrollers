/*
 * Practicum 2.c
 *
 * Created: 2/6/2019 10:24:18 AM
 * Author : paulh, bou & Carlos
 */ 
#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int digit = 0;

typedef struct {
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

const unsigned char
NUMBERS[16] =
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
	0x7C, // B
	0x39, // C
	0x5E, // D
	0x79, // E
};

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void display(int digit){
	if( 0 <= digit && digit <= 14){
		PORTA = NUMBERS[digit];
	}
	else {
		PORTA = NUMBERS[14];
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

int b4(){
	PATTERN_STRUCT pattern[] = {
		{0x00, 100}, {0x01, 100}, {0x02, 100}, {0x04, 100}, {0x08, 100}, {0x10, 100}, {0x20, 100}, {0x40, 100}, {0x80, 100},
		{0x80, 100}, {0x40, 100}, {0x20, 100}, {0x10, 100}, {0x08, 100}, {0x04, 100}, {0x02, 100}, {0x01, 100}, {0x00, 100},
		{0x00, 100},
		{0x81, 100}, {0x42, 100}, {0x24, 100}, {0x18, 100}, {0x0F, 200}, {0xF0, 200}, {0x0F, 200}, {0xF0, 200},
		{0x00, 0}
	};
	
	DDRA = 0xFF;

	
	while (1)
	{

		for(int i = 0; i < (sizeof(pattern)/sizeof(pattern[0])); i++) {
			PORTA = pattern[i].data;
			
			wait(pattern[i].delay);
		}
	}
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
		b4();
		//if(PIND & 0x03 == 0x03) {
			//digit =0;
			//PORTA = NUMBERS[digit];
		//}
	}

	return 1;
}




