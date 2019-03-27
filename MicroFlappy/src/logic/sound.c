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

#define UNDEFINED -1

SoundMusic update_music;
int16_t update_sound_index = UNDEFINED;

void SoundTest(void)
{
	SoundInit();
	
	SoundTune song[5];
	uint16_t i;
	for(i = 0; i < 5; i++) //create default song
	{
		song[i] = (SoundTune) {.duration_us = 1000000, .freq_Hz = 250 * (i+1)};
	}
		
	SoundPlayMusic((SoundMusic) {.tunes = song, .tunesAmount = 10});
}

void SoundInit(void)
{
	BuzzerInit();
}

void SoundSetUpdateMusic(SoundMusic music)
{
	update_music = music;
	update_sound_index = 0;
}

void SoundUpdate(void)
{
	if(update_sound_index == UNDEFINED)
	{
		Delay_ms(100);
		return;
	}
	
	SoundPlayTune(update_music.tunes[update_sound_index]);
	
	update_sound_index++;
	
	if(update_sound_index >= update_music.tunesAmount) //checks if upped update_music index equals to tunesAmount
	{
		update_sound_index = UNDEFINED;
	}
}

void SoundPlayMusic(SoundMusic music)
{
	uint16_t i;
	for (i = 0; i < music.tunesAmount; i++)
	{
		SoundPlayTune(music.tunes[i]);
	}
}

void SoundPlayTune(SoundTune tune)
{
	SoundPlay(tune.duration_us, tune.freq_Hz);
}

void SoundPlay(uint32_t duration_us, uint32_t freq_Hz)
{
	uint32_t delay_us = 1000000 / freq_Hz;
	uint32_t i;
		
	for (i = 0; i < duration_us; i += delay_us)
	{
		BuzzerBeep();
		Delay_us(delay_us);
	}
}
