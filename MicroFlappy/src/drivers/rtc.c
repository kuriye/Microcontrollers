/*
 * rtc.c
 *
 * Created: 20/03/2019 09:11:33
 *  Author:	Paul Hobbel
 */ 

#include <stdio.h>
#include <avr/io.h>
#include "drivers/i2c.h"
#include "drivers/rtc.h"

#define DS1307_ID			0xD0	// DS1307 ID

#define DS1307_SEC_REG		0x00	// Address to access Ds1307 SEC register
#define DS1307_CONTROL_REG	0x07	// Address to access Ds1307 CONTROL register

void RtcInit()
{
	I2CStart();

	I2CSelect(DS1307_ID, I2C_SEL_MODE_W);
	
	I2CWrite(DS1307_CONTROL_REG);	// Select the Ds1307 ControlRegister to configure Ds1307
	I2CWrite(0x00);					// Write 0x00 to Control register to disable SQW-Out

	I2CStop();
}

void RtcSetDateTime(rtc_t *rtc)
{
	I2CStart();

	I2CSelect(DS1307_ID, I2C_SEL_MODE_W);
	I2CWrite(DS1307_SEC_REG);		// Request sec RAM address at 00H

	I2CWrite(rtc->sec);				// Write sec from RAM address 00H
	I2CWrite(rtc->min);				// Write min from RAM address 01H
	I2CWrite(rtc->hour);			// Write hour from RAM address 02H
	I2CWrite(rtc->wday);			// Write wday on RAM address 03H
	I2CWrite(rtc->mday);			// Write mday on RAM address 04H
	I2CWrite(rtc->mon);				// Write month on RAM address 05H
	I2CWrite(rtc->year);			// Write year on RAM address 06h

	I2CStop();
}

void RtcGetDateTime(rtc_t *rtc)
{
	I2CStart();

	I2CSelect(DS1307_ID, I2C_SEL_MODE_W);
	I2CWrite(DS1307_SEC_REG);		// Request Sec RAM address at 00H

	I2CStop();

	I2CStart();
	I2CSelect(DS1307_ID, I2C_SEL_MODE_R);

	rtc->sec = I2CRead(1);			// Read sec and return Positive ACK
	rtc->min = I2CRead(1);			// Read min and return Positive ACK
	rtc->hour = I2CRead(1);			// Read hour and return Negative/No ACK
	rtc->wday = I2CRead(1);			// Read wday and return Positive ACK
	rtc->mday = I2CRead(1);			// Read mday and return Positive ACK
	rtc->mon = I2CRead(1);			// Read month and return Positive ACK
	rtc->year = I2CRead(0);			// Read year and return Negative/No ACK

	I2CStop();
}
