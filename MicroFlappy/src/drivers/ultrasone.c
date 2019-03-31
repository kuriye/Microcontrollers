/*
 * ultrasone.c
 *
 * Created: 27/03/2019 15:17:28
 *  Author: Bou's Laptop
 */ 
#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "drivers/ultrasone.h"

#define TRIGGER_PIN		(1 << 0)

uint32_t distance = 0;

ISR(INT4_vect)
{
	// Rising edge: Enable timer3, we where listening for Rising Edge
	if(EICRB & (1 << ISC40))
	{
		//EIMSK = 0;
		EICRB = (1 << ISC41);				 // Switch to falling edge
		//EIMSK = (1 << INT4);
		
		TCCR3B = (1 << CS30);				 // Enable timer 3
		TCNT3 = 0;							 // Reset timer 3
	}
	
	// Falling edge: Disable timer3 and capture pulse
	else
	{
		//EIMSK = 0;
		EICRB = (1 << ISC41) | (1 << ISC40); // Switch to rising edge
		//EIMSK = (1 << INT4);
		
		TCCR3B = 0;							 // Stop timer 3
		distance = TCNT3 / 58;				 // Calculate distance
	}
}

void UltrasoneInit() 
{
	DDRE = 0x01;
	PORTE = 0xFF;
	
	EICRB = (1 << ISC41) | (1 << ISC40);	// Set interupt on rising edge
	EIMSK = (1 << INT4);					// Enable interrupt INT4 (PORTE4)
	
	sei();
}

uint32_t UltrasoneGetDistance()
{
	return distance;
}

void UltrasoneUpdate()
{
	// Trigger the ultrasone trigger pin
	PORTE |= TRIGGER_PIN;
	_delay_us(10);
	PORTE &= ~TRIGGER_PIN;
}



