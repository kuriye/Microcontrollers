/*
 * Practicum 2.c
 *
 * Created: 2/6/2019 10:24:18 AM
 * Author : paulh, bou & Carlos
 */ 
#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef struct {
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main( void )
{
	PATTERN_STRUCT pattern[] = {
		{0x00, 100}, {0x01, 100}, {0x02, 100}, {0x04, 100}, {0x08, 100}, {0x10, 100}, {0x20, 100}, {0x40, 100}, {0x80, 100},
		{0x80, 100}, {0x40, 100}, {0x20, 100}, {0x10, 100}, {0x08, 100}, {0x04, 100}, {0x02, 100}, {0x01, 100}, {0x00, 100},
		{0x00, 100},
		{0x81, 100}, {0x42, 100}, {0x24, 100}, {0x18, 100}, {0x0F, 200}, {0xF0, 200}, {0x0F, 200}, {0xF0, 200},
		{0x00, 0}
	};
	
	DDRA = 0xFF;

	
	while (1)
	{

		for(int i = 0; i < (sizeof(pattern)/sizeof(pattern[0])); i++) {
			PORTA = pattern[i].data;
			
			wait(pattern[i].delay);
		}
	}

	return 1;
}




