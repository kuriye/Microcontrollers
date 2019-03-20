/*
 * buzzer.h
 *
 * Created: 20/03/2019 09:15:40
 *  Author: Bou's Laptop
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
 * \brief - BuzzerBuzz turns on the Buzzer for the specified ms
 * 
 * \param ms - the duration of the buzz
 * 
 * \return void
 */
void BuzzerBuzz(uint16_t ms);

#endif /* BUZZER_H_ */