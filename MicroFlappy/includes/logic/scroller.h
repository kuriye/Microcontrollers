/*
 * scroller.h
 *
 * Created: 3/28/2019 7:46:38 PM
 *  Author: paulh
 */ 


#ifndef SCROLLER_H_
#define SCROLLER_H_

#define TEXT_MAX_SIZE 255

/**
 * \brief - Initializes the Scroller Module
 * 
 * \return void
 */
void ScrollerInit(void);

/**
 * \brief - Draws a string to the display
 * 
 * \param text - the string that needs to be drawn
 * 
 * \return void
 */
void ScrollerSetText(char text[TEXT_MAX_SIZE]);

/**
 * \brief - Sets the update speed
 * 
 * \param speed - the speed in ms
 * 
 * \return void
 */
void ScrollerSetSpeed(uint8_t speed);

/**
 * \brief - to scroll the string over the display
 * 
 * \return void
 */
void ScrollerUpdate(void);


#endif /* SCROLLER_H_ */