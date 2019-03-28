/*
 * buzzer.h
 *
 * Created: 20/03/2019 09:15:40
 *  Author: Carlos Cadel
 */ 

#ifndef EASYBUZZ_H_
#define EASYBUZZ_H_


/**
 * \brief - initialize the buzzer
 * 
 * 
 * \return void
 */
void BuzzerInit();

/**
 * \brief - Sets the sound with PWM to a certain frequency
 * 
 * \param frequency - the desired frequency
 * 
 * \return void
 */
void BuzzerSetFrequency(int frequency);

/**
 * \brief - To turn the sound off
 * 
 * 
 * \return void
 */
void BuzzerPwmOff();

#endif /* EASYBUZZ_H_ */