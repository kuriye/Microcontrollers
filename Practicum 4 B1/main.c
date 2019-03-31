/*
 * Practicum 4 B1.c
 *
 * Created: 20/02/2019 10:27:57
 * Author : Carlos Cadel, Paul Hobbel & Boudewijn Groeneboer
 */ 
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000L

int main(void)
{
	DDRF = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	//ADC Init:
	ADMUX =	 0b01100000; //Channel: ADC0
	ADCSRA = 0b11100110;
	
    while (1) 
    {
		PORTB = ADCL;
		PORTA = ADCH;
		_delay_ms(100);
    }
}

