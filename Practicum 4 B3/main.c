/*
 * Practicum 4 B3.c
 *
 * Created: 20/02/2019 11:50:51
 * Author : Carlos Cadel, Paul Hobbel & Boudewijn Groeneboer
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define F_CPU 8000000L
#define BIT(x)	(1 << (x))

int main(void)
{
	lcd_init();
	lcd_clear();
	
	DDRF = 0x00;
	DDRA = 0xFF;
	
	//ADC Init:
	ADMUX =	 0b11100001; //Channel: ADC1
	ADCSRA = 0b11100110;
	
	lcd_set_cursor(3);
	lcd_display_text("C");
	char temperature[5];
	
	while (1)
	{		
		int temperatureInt = ADCH << 1;
		
		PORTA = temperatureInt;
		
		sprintf(temperature, "%d", temperatureInt);
		lcd_set_cursor(0);
		lcd_display_text(temperature);
		
		_delay_ms(5000);
	}
}

