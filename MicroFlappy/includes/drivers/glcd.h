/*
 * glcd.h
 *
 * Created: 20/03/2019 09:15:20
 *  Author: Bou's Laptop
 */ 


#ifndef GLCD_H_
#define GLCD_H_

#define DatabBusA	PORTA
#define DataBusDirectionA DDRA
#define DataBusInputA PINA

#define ControlBusE PORTE
#define ControlBusDirectionE DDRE

#define GLCD_CS1 2
#define GLCD_CS2 3
#define GLCD_RS 4
#define GLCD_RW 5
#define GLCD_EN 6
#define GLCD_E7 7


typedef struct{
	uint8_t PageNum;
	uint8_t LineNum;
	uint8_t CursorPos;
	uint8_t Invertdisplay;
}GLCD_Config;

/**
 * \brief 
 * 
 * 
 * \return void
 */
void GlcdInit(void);

/**
 * \brief 
 * 
 * \param Command
 * 
 * \return void
 */
void GlcdCommand(char Command);


void GlcdBusyChecker(void);

void GlcdClear(void);

void GLCD_GoToPage(uint8_t pageNumber);

void  GLCD_GoToLine(uint8_t var_lineNumber_u8);

static void glcd_DataWrite( uint8_t data);

static void GlcdToScreen0(void);

static void GlcdToScreen1(void);



#endif /* GLCD_H_ */