/*
 * sound.c
 *
 * Created: 20/03/2019 13:11:41
 *  Author: Carlos Cadel
 */ 

#include <avr/io.h>
#include "drivers\buzzer.h"
#include "logic\delay.h"
#include "logic\sound.h"

void SoundTest(void)
{
	SoundInit();
	
	SoundTune song[10];
	uint16_t i;
	for(i = 0; i < 10; i++)
	{
		song[i] = (SoundTune) {.duration_us = 1000000, .freq_Hz = 250 * (i+1)};
	}
	
	SoundPlayMusic(song, 10);
}

void SoundInit(void)
{
	BuzzerInit();
}

void SoundUpdate(void)
{
	
}

void SoundPlayMusic(SoundTune* music, uint16_t tuneAmount)
{
	uint16_t i;
	for (i = 0; i < tuneAmount; i++)
	{
		SoundBuzzTune(music[i]);
	}
}

void SoundBuzzTune(SoundTune tune)
{
	SoundBuzz(tune.duration_us, tune.freq_Hz);
}

void SoundBuzz(uint32_t duration_us, uint32_t freq_Hz)
{
	uint32_t delay_us = 1000000 / freq_Hz;
	uint32_t i;
		
	for (i = 0; i < duration_us; i += delay_us)
	{
		BuzzerBeep();
		Delay_us(delay_us);
	}
}
