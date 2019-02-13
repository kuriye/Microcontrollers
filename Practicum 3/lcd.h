/*
 * lcd.h
 *
 * Created: 13/02/2019 10:56:29
 *  Author: Bou
 */ 


#ifndef LCD_H_
#define LCD_H_

void init();
void display_text(char *str);
void set_cursor(int position);

#endif /* LCD_H_ */