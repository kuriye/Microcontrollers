/*
 * Practicum 3.c
 *
 * Created: 13/02/2019 10:55:32
 * Author : Bou
 */ 
#define F_CPU 8000000L
#include <avr/io.h>
#include <avr/interrupt.h>

int counter = 0;
int ms_counter = 0;
int mses[] = {25, 15};
ISR(TIMER2_COMP_vect)
{
	if((++counter) > mses[ms_counter])
	{
		PORTD ^= 1;
		TCNT2 = 0;
		ms_counter = (ms_counter+1)%2;
		counter = 0;
	}
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

	TCNT2 = -1; // of TCNT2=0xf6
	TIMSK |= BIT(6);
	TCCR2 = 0b00011111;
	
	DDRD &= ~BIT(7);

	//enable interupts
	sei();
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
	b3();
	
    while (1) 
    {
    }
}