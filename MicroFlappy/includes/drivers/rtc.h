/*
 * rtc.h
 *
 * Created: 20/03/2019 09:15:28
 *  Author: Paul Hobbel
 */ 

#ifndef RTC_DRIVER_H_
#define RTC_DRIVER_H_

typedef struct
{
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t wday;
	uint8_t mday;
	uint8_t mon;
	uint8_t year;
} rtc_t;


/**
 * \brief Initializes the DS1307 RTC
 * 
 * \return void
 */
void RtcInit(void);


/**
 * \brief Updates the the date and time of the DS1307 RTC
 * 
 * \param rtc Pointer to the rtc_t type
 * 
 * \return void
 */
void RtcSetDateTime(rtc_t *rtc);


/**
 * \brief Gets the date and time of the DS1307 RTC
 * 
 * \param rtc Pointer to the rtc_t type
 * 
 * \return void
 */
void RtcGetDateTime(rtc_t *rtc);


#endif /* RTC_DRIVER_H_ */