/*
 * Practicum 3.c
 *
 * Created: 13/02/2019 10:55:32
 * Author : Bou
 */ 
#define F_CPU 8000000L
#include <avr/io.h>
#include "lcd.h"


int main(void)
{
	init();
	display_text("Hello World!");
	
    while (1) 
    {
    }
}
