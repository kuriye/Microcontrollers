/*
 * ultrasone.c
 *
 * Created: 27/03/2019 15:17:28
 *  Author: Bou's Laptop
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "logic/delay.h"
#include "drivers/gpio.h"
#include "drivers/lcd.h"

ISR( INT0_vect )
{
	
}

void Ultrasonicinit() 
{
	DDRE = 0xFF;	//0:OUTPUT 1-7:INPUT
	
	EICRB |= 0x0B;
	EIMSK |= 0x03;
	
	sei();
}

void Trigger() 
{
	BitSet(PORTE, 0);
	UpdateBit(PORTE ,0, LOW);
	Delay_us(2);
	UpdateBit(PORTE ,0, HIGH);
	Delay_ms(10000);
	UpdateBit(PORTE ,0, LOW);
}



