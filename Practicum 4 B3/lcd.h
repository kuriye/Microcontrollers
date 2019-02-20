/*
 * lcd.h
 *
 * Created: 13/02/2019 10:56:29
 *  Author: Bou
 */ 


#ifndef LCD_H_
#define LCD_H_

void lcd_init();
void lcd_display_text(char *str);
void lcd_set_cursor(int position);
void lcd_clear();

#endif /* LCD_H_ */