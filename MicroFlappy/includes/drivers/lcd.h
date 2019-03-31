/*
 * lcd.h
 *
 * Created: 20/03/2019 09:15:11
 *  Author: Bou's Laptop
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#define CMD_LCD_CLEAR                0x01
#define CMD_LCD_RETURN_HOME          0x02
#define CMD_DISPLAY_ON_CURSOR_OFF    0x0C
#define CMD_DISPLAY_ON_CURSOR_ON     0x0E
#define CMD_DISPLAY_ON_CURSOR_BLINK  0x0F
#define CMD_LCD_FOUR_BIT_MODE        0x28
#define CMD_LCD_EIGHT_BIT_MODE       0x38

typedef enum
{
	LCD_LINE_0 = 0x00,
	LCD_LINE_1 = 0x01
} LCD_LINE;

/**
 * \brief - LcdCommand is used to let the chip now which command it will do
 * 
 * \param command - Give the command the chip has to perform
 * 
 * \return void
 */
void LcdCommand( unsigned char command);

/**
 * \brief - LcdWriteChar is used to right a single character to the LCD screen
 * 
 * \param byte - A single character
 * 
 * \return void
 */
void LcdWriteChar(unsigned char byte);


/**
 * \brief - LcdInit initialize the LCD screen 
 * 
 * 
 * \return void
 */
void LcdInit();


/**
 * \brief - LcdDisplayText prints a string of text to the screen
 * 
 * \param str - the string that needs to be printed
 * 
 * \return void
 */
void LcdDisplayText(char *str);

/**
 * \brief - LcdSetCursor sets the cursor to the given location
 * 
 * \param position - the position the cursor is to be set to
 * 
 * \return void
 */
void LcdSetCursor(int position);

/**
 * \brief - LcdClear clears the screen of the board
 * 
 * 
 * \return void
 */
void LcdClear();

#endif /* LCD_DRIVER_H_ */