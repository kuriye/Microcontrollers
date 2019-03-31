/*
 * i2c.c
 *
 * Created: 3/20/2019 9:37:07 AM
 *  Author: paulh
 */ 
#include <avr/io.h>
#include <stdint.h>

#include "drivers/i2c.h"

void I2CInit()
{
	TWSR=0x00;
	TWBR=0x20;
}

void I2CStart()
{
	TWCR = (1<<TWINT) | (1<< TWSTA) | (1 << TWEN);
	I2CWait();
}

void I2CWait()
{
	while(!(TWCR & (1<<TWINT)));
}

void I2CStop(void)
{
	TWCR = ((1<< TWINT) | (1<<TWEN) | (1<<TWSTO));
}

void I2CSelect(uint8_t addr, I2C_SEL_MODE mode){
	
	TWDR = (addr & 0xFE) | (mode);
	TWCR = (1 <<TWINT ) | (1 <<TWEN);
	I2CWait();
}

void I2CWrite(uint8_t data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	I2CWait();
}

uint8_t I2CRead(uint8_t options)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (options << TWEA);
	I2CWait();
	return TWDR;
}