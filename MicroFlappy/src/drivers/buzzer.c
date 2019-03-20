/*
 * buzzer.c
 *
 * Created: 20/03/2019 09:12:07
 * Author: Carlos Cadel
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "logic/delay.h"
#include "drivers/lcd.h"

void BuzzerInit(void)
{
	DDRB = 0xff;		//PORTB is output
}

void BuzzerBuzz(uint32_t duration_us, uint32_t freq_Hz)
{
	uint32_t delay_us = 1000000 / freq_Hz;
	uint32_t i;
	
	for (i = 0; i < duration_us; i += delay_us)
	{
		PORTB = 0xff;        // Turn ON the Buzzer conneted to PORTB
		PORTB = 0x00;        // Turn OFF the Buzzer connected to PORTB
		
		Delay_us(delay_us);
	}
}