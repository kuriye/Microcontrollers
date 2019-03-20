/*
 * buzzer.c
 *
 * Created: 20/03/2019 09:12:07
 * Author: Carlos Cadel
 */ 

#include <avr/io.h>
#include "logic/delay.h"

void BuzzerInit(void)
{
	DDRB = 0xff;		//PORTB is output
}

void BuzzerBuzz(uint16_t ms)
{
	PORTB = 0xff;        // Turn ON the Buzzer conneted to PORTB
	Delay_ms(ms);		 // Wait for some time
	PORTB = 0x00;        // Turn OFF the Buzzer connected to PORTB
}