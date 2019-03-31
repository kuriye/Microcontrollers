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
 * \brief - Sets the update speed for the Ultrasonic module
 * 
 * \param speed - The speed in ms
 * 
 * \return void
 */
void UltrasoneSetSpeed(uint8_t speed);


/**
 * \brief - Updates the Ultrasonic hardware
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