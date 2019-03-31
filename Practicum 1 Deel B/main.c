#define F_CPU 8000000L
#define BIT(x) (1 << x)

#include <avr/io.h>
#include <util/delay.h>
#include "pattern.h"
#include "smartcontrol.h"

void b2() {
	DDRD = 0xFF;
	
	while (1)
	{
		PORTD = BIT(7);
		_delay_ms(500);
		PORTD = BIT(6);
		_delay_ms(500);
	}

}

void b3() {
	PORTC = 0x10;
	DDRD = 0xFF;
	
	while(1) {
		if(PINC & 0b0000001) {
			PORTD ^= BIT(7);
			_delay_ms(250);
		} else {
			PORTD = 0x00;
		}
	}
}

void b4() {
	DDRD = 0xFF;
	int counter = 0;
	
	while(1) {
		PORTD = BIT(counter);
		_delay_ms(50);
		counter++;
		if(counter > 7) {
			counter = 0;
		}
	}
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void b5() {
	PATTERN_STRUCT pattern[] = {
		{0x00, 100}, {0x01, 100}, {0x02, 100}, {0x04, 100}, {0x08, 100}, {0x10, 100}, {0x20, 100}, {0x40, 100}, {0x80, 100},
		{0x80, 100}, {0x40, 100}, {0x20, 100}, {0x10, 100}, {0x08, 100}, {0x04, 100}, {0x02, 100}, {0x01, 100}, {0x00, 100},
		{0x00, 100},
		{0x81, 100}, {0x42, 100}, {0x24, 100}, {0x18, 100}, {0x0F, 200}, {0xF0, 200}, {0x0F, 200}, {0xF0, 200},
		{0x00, 0}
	};
	
	DDRA = 0xFF;	
	DDRB = 0xFF;	
	DDRC = 0xFF;	
	DDRD = 0xFF;	
	DDRE = 0xFF;
	DDRF = 0xFF;
	DDRG = 0xFF;		
	
	while (1)
	{

		for(int i = 0; i < (sizeof(pattern)/sizeof(pattern[0])); i++) {
			PORTA = pattern[i].data;
			PORTB = pattern[i].data;
			PORTC = pattern[i].data;
			PORTD = pattern[i].data;
			//PORTE = pattern[i].data;
			PORTF = pattern[i].data;
			PORTG = pattern[i].data;
		
			wait(pattern[i].delay);
		}
	}
}

void b6(){
	PORTC = 0x10;
	DDRD = 0xFF;
	int mode = 0;
	
	while(1) {
		PORTD ^= BIT(7);
		if(PINC & 0b0000001) {
			mode ^= 1;
		}
		if(mode == 0) {
			wait(1000);
		} else {
			wait(250);
		}
	}
}

void b7() {
	while(1)
	{
		for(int i = 1; i <= 6; i++)
		{
			setCharliePlexingLed(i);
			wait(100);
		}

		for(int i = 6; i >= 1; i--)
		{
			setCharliePlexingLed(i);
			wait(100);
		}
	}
}


int main( void )
{
	b7();

	return 1;
}