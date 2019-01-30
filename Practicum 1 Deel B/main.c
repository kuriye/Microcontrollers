/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** knipper.c
**
** Beschrijving:	Toggle even en oneven leds PORTD  
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c knipper.c
**					avr-gcc -g -mmcu=atmega128 -o knipper.elf knipper.o
**					avr-objcopy -O ihex knipper.elf knipper.hex 
**					or type 'make'
** Author: 			dkroeske@gmail.com
** -------------------------------------------------------------------------*/

#define F_CPU 8000000L
#define PIN(x) (1 << x)

#include <avr/io.h>
#include <util/delay.h>

void b2() {
	while (1)
	{
		PORTD = PIN(7);
		_delay_ms(500);
		PORTD = PIN(6);
		_delay_ms(500);
	}
}

int main( void )
{
	
	DDRD = 0xFF;			// All pins PORTD are set to output 
	
	b2();

	return 1;
}