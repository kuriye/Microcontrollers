/*
 * buzzer.c
 *
 * Created: 20/03/2019 09:12:07
 * Author: Carlos Cadel
 */ 

#include <avr/io.h>
#include "drivers/buzzer.h"

void BuzzerInit(void)
{
	DDRB = 0xff;		//PORTB is output
}

void BuzzerBeep(void)
{
	PORTB = 0xff;		//Turn ON the Buzzer conneted to PORTB
	PORTB = 0x00;		//Turn OFF the Buzzer connected to PORTB
}
