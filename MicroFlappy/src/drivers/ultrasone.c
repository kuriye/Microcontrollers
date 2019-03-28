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

#define TRIGGER_PIN (1 << 0)

uint32_t overflow = 0;
uint32_t distance = 0;

ISR(TIMER3_OVF_vect)
{
	overflow++;
}

void UltrasoneInit() 
{
	DDRE = 0x01;
	PORTE = 0xFF;
	
	ETIMSK = (1 << TOIE3);	/* Enable Timer3 overflow interrupts */
	TCCR3A = 0;				/* Set all bit to zero Normal operation */
	
	sei();
}

void UltrasoneTrigger()
{
	PORTE |= TRIGGER_PIN;
	_delay_us(10);
	PORTE &= ~TRIGGER_PIN;
}

uint32_t UltrasoneGetDistance()
{
	return distance;
}

void UltrasoneUpdate()
{
	uint32_t count;
	
	UltrasoneTrigger();
		
	/* Clear Timer Counter, 
	start timer on rising edge with no prescaler, 
	clear input capture flag and 
	clear overflow flag. */
	TCNT3 = 0; 
	TCCR3B |= ((1 << ICES3) | (1 << CS30)); 
	ETIFR = 1 << ICF3; 
	//ETIFR = 1 << TOV3;
	
	/* Wait for rising edge */
	while((ETIFR & (1 << ICF3)) == 0);
	TCNT3 = 0;
	TCCR3B = (1 << CS30);
	ETIFR = 1 << ICF3;
	//ETIFR = 1 << TOV3;
	overflow = 0;
		
	/* Wait for falling edge */
	while((ETIFR & (1 << ICF3)) == 0);
	
	count = ICR3 + (65535 * (int)overflow);
	distance = count / 58;
}



