/*
 * MicroFlappy.c
 *
 * Created: 20/03/2019 09:09:16
 * Author : Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include "drivers/buzzer.h"
#include "logic/delay.h"

int main(void)
{
	BuzzerInit();
	
    while (1) 
    {
		BuzzerBuzz(2000);
		Delay_ms(10000);
    }
}

