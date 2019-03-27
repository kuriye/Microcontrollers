/*
 * ledmatrix.c
 *
 * Author: Carlos Cadel
 */ 

// Ignore pragma warnings, because Atmel doesn't like code regions for some reason
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

#include <avr/io.h>

#include "drivers/ledmatrix.h"

#define D0_I2C_ADDR	((0x70 + 0) << 1)

// Function declarations
void twi_init(void);
void matrix_init_display(int);
void matrix_clear_display(int);
void matrix_fill_display(int);

void wait(int);
void draw_row(int, int, int);
void shift_data(int *);

void twi_start(void);
void twi_stop(void);
void twi_tx(unsigned char);

// Initializes both of the matrix displays
void matrix_init()
{
	matrix_init_display(D0_I2C_ADDR);
}

// Initializes the maxtrix display with the given address
void matrix_init_display(int address)
{
	twi_init();		// Init TWI interface

	// Init HT16K22. Page 32 datasheet
	twi_start();
	twi_tx(address);	// Display I2C addres + R/W bit
	twi_tx(0x21);		// Internal osc on (page 10 HT16K33)
	twi_stop();

	twi_start();
	twi_tx(address);	// Display I2C address + R/W bit
	twi_tx(0xA0);		// HT16K33 pins all output
	twi_stop();

	twi_start();
	twi_tx(address);	// Display I2C address + R/W bit
	twi_tx(0xE3);		// Display Dimming 4/16 duty cycle
	twi_stop();

	twi_start();
	twi_tx(address);	// Display I2C address + R/W bit
	twi_tx(0x81);		// Display OFF - Blink On
	twi_stop();
}

// Clears both of the maxtrix displays
void matrix_clear()
{
	matrix_clear_display(D0_I2C_ADDR);
}

// Clears the maxtrix display with the given address
void matrix_clear_display(int address)
{
	for (int y = 0; y < 8; y ++)
		draw_row(address, y, 0);
}

// Fills both of the maxtrix displays
void matrix_fill()
{
	matrix_fill_display(D0_I2C_ADDR);
}

// Fills the maxtrix display with the given address
void matrix_fill_display(int address)
{
	for (int y = 0; y < 8; y ++)
		draw_row(address, y, 0xFF);
}

/* Draws the game field to both of the matrix displays (D0 is the top display, D1 is the bottom display)
 * Field must consist of 0 (off) and 1 (on), and must be constructed like this: field[x][y] (without exceeding the size constraints) */
void matrix_draw_game_field(int field[FIELD_WIDTH][FIELD_HEIGHT])
{
	int x;
	int y;
	int data;
	
	// Draw each row of the game field, from top left (0, 0) with rows as the y-axis
	for (y = 0; y < FIELD_HEIGHT; y++)
	{
		// Create data for an entire row by looping through the array
		data = 0;
		for (x = 0; x < FIELD_WIDTH; x++)
			data |= (1 * field[x][y]) << x;
		
		// Draw the row to the corresponding display
		if (y < 8)
			draw_row(D0_I2C_ADDR, y, data);
	}
}

// row (from 0 - 8) data (from 0 - 8 bit of a byte)
void draw_row(int address, int row, int data)
{
	shift_data(&data);
	
	twi_start();
	twi_tx(address);	// Display I2C addres + R/W bit
	twi_tx(row * 2);	// Address
	twi_tx(data);		// data
	twi_stop();
}

// Change row data because the bits on the display are offset by 1 bit
void shift_data(int *data)
{
	if (*data & 1)	// If bit 1 is set, shift everything to the right and set bit 8 to 1
		*data = (*data - 1) / 2 + (1 << 7);
	else			// If bit 1 is not set, just shift everything to the right
		*data /= 2;
}

// Init TWI interface and set bitrate
void twi_init(void)
{
	TWSR = 0;
	TWBR = 32;						// TWI clock set to 100kHz, prescaler = 0
}

// Generate TWI start condition (page 285 of datasheet)
void twi_start(void)
{
	TWCR = (0x80 | 0x20 | 0x04);	// Set the TWI Control Register in the start condition
	while( 0x00 == (TWCR & 0x80) ); // Wait until the TWINT flag bit is set, then it is done transmitting
}

// Generate TWI stop condition
void twi_stop(void)
{
	TWCR = (0x80 | 0x10 | 0x04);	// Set the TWINT, TWEN and TWSTO bits to 1
}

// Transmit 8 bits of data
void twi_tx(unsigned char data)
{
	TWDR = data;					// Place the data onto the data bus
	TWCR = (0x80 | 0x04);			// Set the TWINT and TWEN bit to 1
	while( 0 == (TWCR & 0x80) );	// Wait until the TWINT flag bit is set, then it is done transmitting
}

