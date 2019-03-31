/*
 * smartcontrol.c
 *
 * Created: 2/1/2019 12:09:18 PM
 *  Author: paulh
 */ 

#include <avr/io.h>
#define BIT(x) (1 << x)

void setState(int highPort, int triPort) {
	PORTA = BIT(highPort);
	DDRA = ~BIT(triPort);
}

 /*
			0	4	7
  * LED1	+	-	=
  * LED2	-	+	=
  * LED3	=	+	-
  * LED4	=	-	+
  * LED5	-	=	+
  * LED6	+	=	-
  */
 void setCharliePlexingLed(int lednr) {
	switch(lednr)
	{
		case 1:
			setState(0, 7);
			break;
		case 2:
			setState(4, 7);
			break;
		case 3:
			setState(4, 0);
			break;
		case 4:
			setState(7, 0);
			break;
		case 5:
			setState(7, 4);
			break;
		case 6:
			setState(0, 4);
			break;
	}
 }