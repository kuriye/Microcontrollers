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

void SoundTest(void);

/**
 * \brief - SoundInit initializes the buzzer that will be used
 * 
 * \param void
 * 
 * \return void
 */
void SoundInit(void);

/**
 * \brief //TODO: brief
 * 
 * \param void
 * 
 * \return void
 */
void SoundUpdate(void);

void SoundPlayMusic(SoundTune* music, uint16_t tuneAmount);

/**
 * \brief - SoundBuzzTime buzzes for a speficied duration on a specified frequency
 * 
 * \param tune - tune to buzz
 * 
 * \return void
 */
void SoundBuzzTune(SoundTune tune);

/**
 * \brief - SoundBuzz buzzes for a speficied duration on a specified frequency
 * 
 * \param duration_us - duration of the buzz in microseconds
 * \param freq_Hz - frequency of the buzz
 * 
 * \return void
 */
void SoundBuzz(uint32_t duration_us, uint32_t freq_Hz);

#endif /* SOUND_H_ */
