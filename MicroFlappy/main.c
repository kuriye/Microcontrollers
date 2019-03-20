/*
 * MicroFlappy.c
 *
 * Created: 20/03/2019 09:09:16
 * Author : Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <avr/io.h>

#include "drivers/rtc.h"
#include "drivers/lcd.h"
#include "drivers/buzzer.h"

#include "logic/delay.h"


int main(void)
{
	RtcInit();
	LcdInit();
    while (1) 
    {
		//BuzzerInit();
		//BuzzerBuzz(1000);
		//Delay_ms(3000);
    }
}

