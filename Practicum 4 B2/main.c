/*
 * Practicum 4 B2.c
 *
 * Created: 20/02/2019 11:06:45
 * Author : Carlos Cadel, Paul Hobebel & Boudewijn Groeneboer
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000L
#define BIT(x)	(1 << (x))

int main(void)
{
	DDRF = 0x00;
	DDRA = 0xFF;
	
	//ADC Init:
	ADMUX =	 0b11100011; //Channel: ADC3
	ADCSRA = 0b10000110;
	
	while (1)
	{
		ADCSRA |= BIT(6);
		while(ADCSRA & BIT(6)); //Wachten totdat interrupt voorbij is
		PORTA = ADCH;
		
		_delay_ms(2000);
	}
}
