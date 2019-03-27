/*
 * glcd.c
 *
 * Created: 20/03/2019 09:11:20
 *  Author: Bou's Laptop
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "drivers/glcd.h"
#include "logic/delay.h"
#include "drivers/gpio.h"

GLCD_Config GLCD;

void GlcdInit()
{
	ControlBusDirectionE = 0xff; /* Configure the data bus and Control bus as Output */
	DataBusDirectionA = 0xff;
	
	void GlcdToScreen0();
	GlcdCommand(0x3f);
	void GlcdToScreen1();
	GlcdCommand(0x3f);
	
	void GlcdToScreen0();
	GlcdCommand(0xc0);
	void GlcdToScreen1();
	GlcdCommand(0xc0);
}
}

void GlcdCommand(uint8_t Command)
{
	GlcdBusyChecker();
	DatabBusA = Command;
	BitClear(GLCD_RS);
	BitClear(GLCD_RW);
	BitSet(GLCD_EN);
	Delay_us(1);

}

void GlcdBusyChecker()
{
	uint8_t busyflag;
	
	UpdateBit(DataBusDirectionA, GLCD_E7, INPUT);
	BitClear(ControlBusE, GLCD_RS);
	BitSet(ControlBusE, GLCD_RW);
	do 
	{
		BitClear(GLCD_EN);
		Delay_us(1);
		BitSet(GLCD_EN);
		Delay_us(1);
		
		busyflag = IsBitSet(DataBusInputA, GLCD_E7);
	} while (busyflag);
	
	UpdateBit(DataBusDirectionA, GLCD_E7, OUTPUT);
}

void GlcdClear()
{
	uint8_t line, cursor, inversion;

	inversion = GLCD.Invertdisplay;
	GLCD.Invertdisplay = 0x00;
	
	for(line=0; line<8; line++)  /* loop through all the 8lines to clear the display */
	{
		GLCD_GoToLine(line);  /* Go to beginning of the specified line on page0 */
		
		for(cursor=0; cursor<128; cursor++) /* Clear all the 128 pixels of selected line */
		{
			if(cursor == 64)  /* Has the cursor reached end of page0 */
			{
				GLCD_GoToPage(1); /*  then set it to beginning of page1 */
				
			}
			glcd_DataWrite(0x00); /* Clear each pixel by displaying blank */
		}
	}
	
	GLCD.Invertdisplay = inversion;

	GLCD_GoToLine(0);
}

void GLCD_GoToPage(uint8_t pageNumber)
{

    if((pageNumber==0) || (pageNumber ==1))
    { /* for 128/64 GLCD only page 0&1 are supported.
        Select the specified page and move the cursor accordingly */
        if(pageNumber == 0)
        {

            GlcdToScreen0();
        }
        else
        {
            GlcdToScreen1();
        }
        GLCD.PageNum=pageNumber;
        GLCD.CursorPos=0x40;
        GlcdCommand(GLCD.LineNum);
        GlcdCommand(GLCD.CursorPos);
    }
}

void  GLCD_GoToLine(uint8_t var_lineNumber_u8)
{
    if(var_lineNumber_u8 <= 0x07)
    {   /* If the line number is within range
         then move it to specified line on page0 and keep track*/
        GLCD.LineNum = var_lineNumber_u8+0x88;
        GLCD_GoToPage(0);
    }
}

static void glcd_DataWrite( uint8_t data)
{
	GlcdBusyChecker();;
	DatabBusA = data ^ GLCD.Invertdisplay;
	BitSet(GLCD_RS);           // Select the Data Register by pulling RS High
	BitClear(GLCD_RW);           // Select the Write Operation  by pulling RW LOW
	BitSet(GLCD_EN);             // Send a High-to-Low Pulse at Enable Pin
	Delay_us(2);
	BitClear(GLCD_EN);
}

static void GlcdToScreen0()
{
	BitSet(GLCD_CS1);
	BitClear(GLCD_CS2);
}

static void GlcdToScreen1()
{
	BitSet(GLCD_CS2);
	BitClear(GLCD_CS1);
}