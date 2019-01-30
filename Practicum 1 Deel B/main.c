#define F_CPU 8000000L
#define PORT(x) (1 << x)

#include <avr/io.h>
#include <util/delay.h>

void b2() {
	DDRD = 0xFF;
	
	while (1)
	{
		PORTD = PORT(7);
		_delay_ms(500);
		PORTD = PORT(6);
		_delay_ms(500);
	}

}

void b3() {
	PORTC = 0x10;
	DDRD = 0xFF;
	
	while(1) {
		if(PINC & 0b0000001) {
			PORTD ^= PORT(7);
			_delay_ms(250);
		} else {
			PORTD = 0x00;
		}
	}
}

int main( void )
{
	b3();

	return 1;
}