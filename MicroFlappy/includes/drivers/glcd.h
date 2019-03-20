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




#endif /* GLCD_H_ */