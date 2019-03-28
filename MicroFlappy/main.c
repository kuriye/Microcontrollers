/*
 * MicroFlappy.c
 *
 * Created: 20/03/2019 09:09:16
 * Author : Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "drivers/rtc.h"
#include "drivers/lcd.h"
#include "drivers/ledmatrix.h"
#include "drivers/buzzer.h"
#include "includes/drivers/ultrasone.h"
#include "drivers/ledmatrix.h"

#include "logic/time.h"
#include "logic/delay.h"
#include "logic/sound.h"

#define TRIGGER_PIN (1 << 0)
#define ECHO_PIN (1 << 4)

int overflow = 0;

ISR(TIMER3_OVF_vect)
{
	overflow++;
}

int main(void)
{	
	DDRE = 0x01;
	PORTE = 0xFF;
	
	//DDRA = 0x01;		/* Make trigger pin as output */
	//PORTD = 0xFF;
	
	sei();					/* Enable global interrupt */
	ETIMSK = (1 << TOIE3);	/* Enable Timer3 overflow interrupts */
	TCCR3A = 0;				/* Set all bit to zero Normal operation */
	
	
	I2CInit();
	
	//SoundInit();
	
	//LcdInit();
	MatrixInit();
	MatrixClear();
	
	SoundTune song[10];
	uint16_t i;
	for(i = 0; i < 10; i++) //create default song
	{
		//song[i] = (SoundTune) {.duration_us = 1000000, .freq_Hz = 250 * (i+1)};
	}
	
	//SoundSetUpdateMusic((SoundMusic) {.tunes = song, .tunesAmount = 10});
	
	
    while (1)
    {
		MatrixClear();
		PORTE |= TRIGGER_PIN;
		_delay_us(10);
		PORTE &= ~TRIGGER_PIN;
		
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
		
		MatrixFill();
		//_delay_ms(2000);
		//MatrixFill();
		//Delay_ms(1000);
		//MatrixClear();
		//Delay_ms(1000);
		
		//SoundUpdate();
    }
}

