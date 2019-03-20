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

void BuzzerBuzz(uint32_t duration_us, uint32_t freq_Hz);

#endif /* BUZZER_H_ */