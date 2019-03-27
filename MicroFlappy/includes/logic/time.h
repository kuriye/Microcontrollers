/*
 * time.h
 *
 * Created: 3/20/2019 3:01:03 PM
 *  Author: Paul Hobbel
 */ 

#ifndef TIME_LOGIC_H_
#define TIME_LOGIC_H_

/**
 * \brief - Initializes the internal rtc chip
 * 
 * \return void
 */
void TimeInit(void);


/**
 * \brief - Updates the stored time
 * 
 * \return void
 */
void TimeUpdate(void);


/**
 * \brief - Gets the stored time
 * 
 * \return rtc_t
 */
rtc_t TimeGetDateTime(void);

#endif /* TIME_LOGIC_H_ */