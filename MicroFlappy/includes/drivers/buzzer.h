/*
 * buzzer.h
 *
 * Created: 20/03/2019 09:15:40
 *  Author: Carlos Cadel
 */ 

#ifndef BUZZER_H_
#define BUZZER_H_

/**
 * \brief - BuzzerInit initializes the Buzzer on PORTB
 * 
 * \param void
 * 
 * \return void
 */
void BuzzerInit(void);

/**
 * \brief - BuzzerBeep lets the buzzer make a single beep
 * 
 * \param void
 * 
 * \return void
 */
void BuzzerBeep(void);

#endif /* BUZZER_H_ */