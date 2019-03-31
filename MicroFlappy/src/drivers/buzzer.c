/*
 * Buzzer.c
 *
 * Created: 28-Mar-19 11:05:13
 * Author: Boudewijn
 */

#include <avr/io.h>
#include <stdio.h>

#include "drivers/buzzer.h"

void BuzzerInit()
{
	DDRB = 0xFF;
	TCCR1A = 0b10000010;		// compare output at OC1A  (=PB5)
	TCCR1B = 0b00011000;		// fast PWM, TOP=ICR1
}

void BuzzerSetFrequency(int frequency)
{
	int ms = (int)(1.0 / frequency * 1000000.0); // Convert hertz to microseconds
	
	TCCR1B |= (1 << CS11);		// Turn on the 8 times prescaler (which starts the timer)
	ICR1	= ms;				// TOP value for counter
	OCR1A	= ms / 2;			// compare value in between
}

void BuzzerPwmOff()
{
	TCCR1B &= ~(1 << CS11);		// Turn off the prescaler (which stops the timer)
}
