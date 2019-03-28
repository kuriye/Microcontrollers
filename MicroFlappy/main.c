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
#include "includes/drivers/ultrasone.h"

#include "logic/time.h"
#include "logic/delay.h"
#include "logic/sound.h"

int main(void)
{
	TimeInit();
	RtcInit();
	//LcdInit();
	matrix_init();
	SoundInit();
	Ultrasonicinit();
	
	
	Trigger();
	SoundTune song[10];
	uint16_t i;
	for(i = 0; i < 10; i++) //create default song
	{
		song[i] = (SoundTune) {.duration_us = 1000000, .freq_Hz = 250 * (i+1)};
	}
	
	SoundSetUpdateMusic((SoundMusic) {.tunes = song, .tunesAmount = 10});
	
	
    while (1) 
    {
		TimeUpdate();
		LcdSetCursor(0);
		
		SoundUpdate();
    }
}

