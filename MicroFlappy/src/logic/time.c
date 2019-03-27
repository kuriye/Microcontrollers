/*
 * time.c
 *
 * Created: 3/20/2019 2:36:52 PM
 *  Author: paulh
 */ 

#include "drivers/rtc.h"
//#include <stdint.h>

rtc_t datetime;
// uint32_t timestamp;

void TimeInit()
{
	RtcInit();	
}

rtc_t TimeGetDateTime()
{
	return datetime;
}

void TimeUpdate()
{
	RtcGetDateTime(&datetime);
	
	// Calculate timestamp;
	// timestamp = ((datetime.hour * 60L) + datetime.min * 60L) * datetime.sec;
}