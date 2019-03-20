/*
 * gpio.c
 *
 * Created: 3/20/2019 12:32:13 PM
 *  Author: Paul Hobbel
 */ 

#include <stdio.h>
#include <avr/io.h>

#include "drivers/gpio.h"

void GPIOPinDirection(GPIO_PIN pin, GPIO_DIRECTION direction)
{
	uint8_t portNumber = (pin >> 3);	// Divide the pin number by 8 go get the PORT number
	pin = pin & 0x07;					// lower 3-bits contains the bit number of a byte
	
	switch(portNumber)
	{
		case 0:
			UpdateBit(DDRA, pin, direction);
			break;
		case 1:
			UpdateBit(DDRB, pin, direction);
			break;
		case 2:
			UpdateBit(DDRC, pin, direction);
			break;
		case 3:
			UpdateBit(DDRD, pin, direction);
			break;
		case 4:
			UpdateBit(DDRE, pin, direction);
			break;
		case 5:
			UpdateBit(DDRF, pin, direction);
			break;
		case 6:
			UpdateBit(DDRG, pin, direction);
			break;
	}
}

void GPIOPinWrite(GPIO_PIN pin, GPIO_MODE mode)
{
	uint8_t portNumber = (pin >> 3);	// Divide the pin number by 8 go get the PORT number
	pin = pin & 0x07;					// lower 3-bits contains the bit number of a byte
	
	switch(portNumber)
	{
		case 0:
		UpdateBit(PORTA, pin, mode);
		break;
		case 1:
		UpdateBit(PORTB, pin, mode);
		break;
		case 2:
		UpdateBit(PORTC, pin, mode);
		break;
		case 3:
		UpdateBit(PORTD, pin, mode);
		break;
		case 4:
		UpdateBit(PORTE, pin, mode);
		break;
		case 5:
		UpdateBit(PORTF, pin, mode);
		break;
		case 6:
		UpdateBit(PORTG, pin, mode);
		break;
	}
}

uint8_t GPIOPinRead(GPIO_PIN pin)
{
	uint8_t portNumber = (pin >> 3);	// Divide the pin number by 8 go get the PORT number
	pin = pin & 0x07;					// lower 3-bits contains the bit number of a byte
	
	switch(portNumber)
	{
		case 0:
			return IsBitSet(PINA, pin);
		case 1:
			return IsBitSet(PINB, pin);
		case 2:
			return IsBitSet(PINC, pin);
		case 3:
			return IsBitSet(PIND, pin);
		case 4:
			return IsBitSet(PINE, pin);
		case 5:
			return IsBitSet(PINF, pin);
		case 6:
			return IsBitSet(PING, pin);
	}
	
	return 0;
}