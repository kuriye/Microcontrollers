/*
 * MicroFlappy.c
 *
 * Created: 20/03/2019 09:09:16
 * Author : Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <stdio.h>
#include <avr/io.h>

#include "drivers/rtc.h"
#include "drivers/lcd.h"
#include "drivers/buzzer.h"

#include "logic/time.h"
#include "logic/delay.h"


int main(void)
{
	TimeInit();
	LcdInit();
    while (1) 
    {
		TimeUpdate();
		
		LcdSetCursor(0);
		Delay_ms(100);
    }
}

