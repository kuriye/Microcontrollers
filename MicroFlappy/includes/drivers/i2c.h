/*
 * i2c.h
 *
 * Created: 3/20/2019 9:46:32 AM
 *  Author: paulh
 */ 


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

/**
 * \brief Initializes the I2C driver
 * 
 * \return void
 */
void I2CInit(void);

/**
 * \brief Sets the correct start condition for the I2C protocol
 *
 * \return void
 */
void I2CStart(void);

/**
 * \brief Waits for the 
 * 
 * \param 
 * 
 * \return void
 */
void I2CWait(void);

void I2CStop(void);

void I2CWrite(uint8_t data);

uint8_t I2CRead(uint8_t options);



#endif /* I2C_DRIVER_H_ */