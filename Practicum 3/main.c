/*
 * Practicum 3.c
 *
 * Created: 13/02/2019 10:55:32
 * Author : Bou
 */ 
#define F_CPU 8000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include <util/delay.h>

#define BIT(x)	(1 << (x))
char numbers[4];

ISR( TIMER2_OVF_vect )
{
	sprintf(numbers, "%d", TCNT2);
	//set_cursor(0);
	display_text(numbers);
	set_cursor(0);
}

void b1()
{
	init();
	set_cursor(4);
	display_text("Hello World!");
}

void b2()
{
	init();

	TCCR2 = (1 << COM21) | (1 << COM20) |(1 << CS22) | (1 << CS21);

	DDRD &= ~BIT(7);

	while(1)
	{
		sprintf(numbers, "%d", TCNT2);
		display_text(numbers);
		set_cursor(0);
		_delay_ms(100);
	}
}

b3()
{
	DDRD = 0xff;

	TCNT2 = 0;
	OCR2 = 0x05;
	TCCR2 = (1 << WGM21) | (1 << CS20)| (1 << CS22);
	TIMSK = (1 << OCIE2);
	sei();
}

int main(void)
{
	b2();
	
    while (1) 
    {
    }
}