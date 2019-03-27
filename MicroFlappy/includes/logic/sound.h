/*
 * sound.h
 *
 * Created: 20/03/2019 13:11:22
 *  Author: Carlos Cadel
 */ 

#ifndef SOUND_H_
#define SOUND_H_

typedef struct
{
	uint32_t duration_us;
	uint32_t freq_Hz;
} SoundTune;

typedef struct
{
	SoundTune* tunes;
	uint16_t tunesAmount;
} SoundMusic;

//Functions:

void SoundTest(void);

/**
 * \brief - SoundInit initializes the buzzer that will be used
 * 
 * \param void
 * 
 * \return void
 */
void SoundInit(void);

void SoundSetUpdateMusic(SoundMusic music);

void SoundUpdate(void);

void SoundPlayMusic(SoundMusic music);

/**
 * \brief - SoundPlayTime plays for a speficied duration on a specified frequency
 * 
 * \param tune - tune to play
 * 
 * \return void
 */
void SoundPlayTune(SoundTune tune);

/**
 * \brief - SoundPlay plays for a speficied duration on a specified frequency
 * 
 * \param duration_us - duration of the sound in microseconds
 * \param freq_Hz - frequency of the sound
 * 
 * \return void
 */
void SoundPlay(uint32_t duration_us, uint32_t freq_Hz);

#endif /* SOUND_H_ */
