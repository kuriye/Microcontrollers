/*
 * MicroFlappy.c
 *
 * Created: 20/03/2019 09:09:16
 * Author : Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <stdio.h>
#include "drivers/buzzer.h"
#include "logic/delay.h"

int main(void)
{
	printf("\nHello world!");
	
	BuzzerInit();
	BuzzerBuzz(1000000, 3600);
	
    while (1) 
    {
		
    }
}

