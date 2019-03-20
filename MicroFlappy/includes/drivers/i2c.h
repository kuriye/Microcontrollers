/*
 * i2c.h
 *
 * Created: 3/20/2019 9:46:32 AM
 *  Author: Paul Hobbel
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
 * \brief Waits for the I2C to trigger
 * 
 * \param 
 * 
 * \return void
 */
void I2CWait(void);


/**
 * \brief Generates the I2C stop condition.
 * 
 * \param 
 * 
 * \return void
 */
void I2CStop(void);


/**
 * \brief Sends data on the SDA line using the I2C protocol.
 * 
 * \param data 8bit data to be sent.
 * 
 * \return void
 */
void I2CWrite(uint8_t data);


/**
 * \brief Reads a byte from the SDA line using the I2C protocol.
 * 
 * \param options
 * 
 * \return uint8_t received byte
 */
uint8_t I2CRead(uint8_t options);



#endif /* I2C_DRIVER_H_ */