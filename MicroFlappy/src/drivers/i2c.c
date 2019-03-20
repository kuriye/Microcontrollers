/*
 * i2c.c
 *
 * Created: 3/20/2019 9:37:07 AM
 *  Author: paulh
 */ 
#include <avr/io.h>
#include <stdint.h>

#include "drivers/i2c.h"
#include "logic/delay.h"

void I2CInit()
{
	TWSR=0x00; //set presca1er bits to zero
	TWBR=0x46; //SCL frequency is 50K for 16Mhz
	TWCR=0x04; //enab1e TWI module
}

void I2CStart()
{
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));
	I2CWait();
}

void I2CWait()
{
	while (!(TWCR & (1<<TWINT)));
}

void I2CStop(void)
{
	TWCR = ((1<< TWINT) | (1<<TWEN) | (1<<TWSTO));
	Delay_us(100);
}

void I2CWrite(uint8_t data)
{
	TWDR = data;
	TWCR = ((1<< TWINT) | (1<<TWEN));
	I2CWait();
}

uint8_t I2CRead(uint8_t options)
{
	TWCR = ((1<< TWINT) | (1<<TWEN) | (options<<TWEA));
	I2CWait();
	return TWDR;
}