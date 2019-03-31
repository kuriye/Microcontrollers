/*
 * MicroFlappy.c
 *
 * Created: 20/03/2019 09:09:16
 * Author : Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <stdio.h>
#include <util/delay.h>

#include "drivers/i2c.h"
#include "drivers/rtc.h"
#include "drivers/lcd.h"
#include "drivers/buzzer.h"
#include "drivers/ultrasone.h"

#include "logic/scroller.h"

char text[16];

int main(void)
{	
	LcdInit();
	
	I2CInit();
	RtcInit();
	
	BuzzerInit();
	UltrasoneInit();
	UltrasoneSetSpeed(50);
	
	ScrollerInit();
	ScrollerSetSpeed(40);
	ScrollerSetText("Nerds are the new cool");
	LcdClear();
	
    while (1)
    {
		rtc_t datetime;
		RtcGetDateTime(&datetime);
		
		UltrasoneUpdate();
		BuzzerSetFrequency(1000 - UltrasoneGetDistance());
		
		sprintf(text, "    %02x:%02x:%02x", datetime.hour, datetime.min, datetime.sec );
		LcdSetCursor(0);
		LcdDisplayText(text);
		
		sprintf(text, "   speed: %-5ld", UltrasoneGetDistance());
		LcdSetCursor(16);
		LcdDisplayText(text);
		
		ScrollerSetSpeed((UltrasoneGetDistance() - 10)/ 50);
		ScrollerUpdate();
		
		_delay_ms(20);
    }
}

