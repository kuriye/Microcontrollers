/*
 * buzzer.c
 *
 * Created: 20/03/2019 09:12:07
 *  Author: Bou's Laptop
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
#include "logic/delay.h"

void BuzzerInit(void)
{
	DDRB = 0xff; //PORTB is output
}

void BuzzerBuzz(uint16_t ms)
{
	PORTB = 0xff;        // Turn ON the Buzzer conneted to PORTC
	Delay_ms(ms);    // Wait for some time
	PORTB = 0x00;        // Turn OFF the Buzzer connected to PORTC
	Delay_ms(ms);      // Wait for some time
}