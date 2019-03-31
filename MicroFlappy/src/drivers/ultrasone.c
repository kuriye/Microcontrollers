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

uint32_t overflow = 0;
uint32_t pulse = 0;
uint32_t distance = 0;

uint8_t ultrasoneUpdateCounter = 0;
uint8_t ultrasoneUpdateSpeed = 0;

//ISR(TIMER3_OVF_vect)
//{
	//overflow++;
//}

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
	
	//ETIMSK = (1 << TOIE3);	/* Enable Timer3 overflow interrupts */
	//TCCR3A = 0;				/* Set all bit to zero Normal operation */
	//EICRB = (1 << ISC41);
	
	EICRB = (1 << ISC41) | (1 << ISC40);
	EIMSK = (1 << INT4);
	
	sei();
}

void UltrasoneSetSpeed(uint8_t speed)
{
	ultrasoneUpdateSpeed = speed;
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
	//if(ultrasoneUpdateCounter >= ultrasoneUpdateSpeed)
	//{
	//	ultrasoneUpdateCounter = 0;	
		UltrasoneTrigger();
		
		//EICRB = (1 << ISC41) | (1 << ISC40);
		//ultrasoneState = STATE_RISING;
		
		/* Clear Timer Counter, 
		start timer on rising edge with no prescaler, 
		clear input capture flag and 
		clear overflow flag. */
		//TCNT3 = 0; 
		//TCCR3B |= ((1 << ICES3) | (1 << CS30)); 
		//ETIFR = 1 << ICF3;
		//ETIFR = 1 << TOV3;
	
		/* Wait for rising edge */
		//while((ETIFR & (1 << ICF3)) == 0); // TODO: Use the interrupt instead so we dont have to wait
		//TCNT3 = 0;
		//TCCR3B = (1 << CS30);
		//ETIFR = 1 << ICF3;
		//ETIFR = 1 << TOV3;
		//overflow = 0;
		
		/* Wait for falling edge */
		//while((ETIFR & (1 << ICF3)) == 0); // TODO: Use the interrupt instead so we dont have to wait

		//distance = (ICR3 + (65535 * overflow)) / 58;
	//}
	
	//ultrasoneUpdateCounter++;
}



