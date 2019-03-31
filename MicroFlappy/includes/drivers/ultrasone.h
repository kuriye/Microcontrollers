/*
 * ultrasone.h
 *
 * Created: 27/03/2019 15:23:09
 *  Author: Bou's Laptop
 */ 


#ifndef ULTRASONE_H_
#define ULTRASONE_H_

/**
 * \brief - Initializes the Ultrasonic module
 *
 * \return void
 */
void UltrasoneInit(void);


/**
 * \brief - Triggers the trigger pin of the ultrasone
 *
 * \return void
 */
void UltrasoneUpdate(void);


/**
 * \brief  - Gets the last calculated distance
 * 
 * \return uint32_t - The distance in mm
 */
uint32_t UltrasoneGetDistance(void);


#endif /* ULTRASONE_H_ */