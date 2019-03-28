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

#include "drivers/rtc.h"
#include "drivers/lcd.h"
#include "drivers/ledmatrix.h"
#include "drivers/buzzer.h"
#include "drivers/ultrasone.h"
#include "drivers/ledmatrix.h"
#include "drivers/i2c.h"

#include "logic/time.h"

int main(void)
{
	I2CInit();
	
	TimeInit();
	BuzzerInit();
	UltrasoneInit();
	
	LcdInit();
	MatrixInit();
	
	LcdClear();
	MatrixClear();
	
	MatrixDrawString("Nerds are the new cool");
	
	
    while (1)
    {
		char *text = "               ";
		rtc_t datetime = TimeGetDateTime();
		UltrasoneUpdate();
		TimeUpdate();
		
		LcdSetCursor(0);
		sprintf(text, "    %02x:%02x:%02x", datetime.hour, datetime.min, datetime.sec );
		LcdDisplayText(text);
		
		LcdSetCursor(16);
		sprintf(text, "   speed: %-5ld", UltrasoneGetDistance());
		LcdDisplayText(text);
		
		BuzzerSetFrequency(1000 - UltrasoneGetDistance());
		
		_delay_ms(10);
		MatrixScrollString();
		//SoundUpdate();
    }
}

