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
#include "logic/sound.h"

int main(void)
{	
	RtcInit();
	LcdInit();
	
	SoundInit();
	
	SoundTune song[10];
	uint16_t i;
	for(i = 0; i < 10; i++) //create default song
	{
		song[i] = (SoundTune) {.duration_us = 100000, .freq_Hz = 250 * (i+1)};
	}
	
	SoundSetUpdateMusic((SoundMusic) {.tunes = song, .tunesAmount = 10});
	
    while (1) 
    {
		SoundUpdate();
    }
}

