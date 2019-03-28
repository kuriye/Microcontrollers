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
#include "logic/delay.h"
#include "logic/sound.h"
#include "logic/matrixCharacters.h"

int main(void)
{
	MatrixCharactersInit();
	I2CInit();
	RtcInit();
	BuzzerInit();
	//SoundInit();
	UltrasoneInit();
	
	LcdInit();
	MatrixInit();
	
	LcdClear();
	MatrixClear();
	
	
	SoundTune song[10];
	uint16_t i;
	for(i = 0; i < 10; i++) //create default song
	{
		//song[i] = (SoundTune) {.duration_us = 1000000, .freq_Hz = 250 * (i+1)};
	}
	
	//SoundSetUpdateMusic((SoundMusic) {.tunes = song, .tunesAmount = 10});
	
	
	MatrixDrawString("ABABAB");
	
	
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
		
		_delay_ms(50);
		MatrixScrollField();
		
		//SoundUpdate();
    }
}

