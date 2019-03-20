/*
 * glcd.c
 *
 * Created: 20/03/2019 09:11:20
 *  Author: Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "drivers/glcd.h"
#include "logic/delay.h"
#include "drivers/gpio.h"

void GlcdInit()
{
	ControlBusDirectionE = 0xff; /* Configure the data bus and Control bus as Output */
	DataBusDirectionA = 0xff;
	
	
	
}

void GlcdCommand(uint8_t Command)
{
	GlcdBusyChecker();
	DatabBusA = Command;
	BitClear(GLCD_RS);
	BitClear(GLCD_RW);
	BitSet(GLCD_EN);
	Delay_us(1);

}

void GlcdBusyChecker()
{
	uint8_t busyflag;
	
	UpdateBit(DataBusDirectionA, GLCD_E7, INPUT);
	BitClear(ControlBusE, GLCD_RS);
	BitSet(ControlBusE, GLCD_RW);
	do 
	{
		BitClear(GLCD_EN);
		Delay_us(1);
		BitSet(GLCD_EN);
		Delay_us(1);
		
		busyflag = IsBitSet(DataBusInputA, GLCD_E7);
	} while (busyflag);
	
	UpdateBit(DataBusDirectionA, GLCD_E7, OUTPUT);
}