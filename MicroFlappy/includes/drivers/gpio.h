/*
 * gpio.h
 *
 * Created: 3/20/2019 12:49:09 PM
 *  Author: Paul Hobbel
 */ 


#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#define  BitMask(bit)			(1<<(bit))
#define  BitSet(x,bit)			((x) |=  BitMask(bit))
#define  BitClear(x,bit)        ((x) &= ~BitMask(bit))
#define  BitToggle(x,bit)       ((x) ^=  BitMask(bit))
#define  UpdateBit(x,bit,val)   ((val)? BitSet(x,bit): BitClear(x,bit))
#define  IsBitSet(x,bit)        (((x)&(BitMask(bit)))!=0u)

typedef enum
{
	PA_0,PA_1,PA_2,PA_3,PA_4,PA_5,PA_6,PA_7,
	PB_0,PB_1,PB_2,PB_3,PB_4,PB_5,PB_6,PB_7,
	PC_0,PC_1,PC_2,PC_3,PC_4,PC_5,PC_6,PC_7,
	PD_0,PD_1,PD_2,PD_3,PD_4,PD_5,PD_6,PD_7,
	PE_0,PE_1,PE_2,PE_3,PE_4,PE_5,PE_6,PE_7,
	PF_0,PF_1,PF_2,PF_3,PF_4,PF_5,PF_6,PF_7,
	PG_0,PG_1,PG_2,PG_3,PG_4,PG_5,PG_6,PG_7,
	P_NC = 0xff
} GPIO_PIN;

typedef enum
{
	INPUT = 0x00,
	OUTPUT = 0x01	

} GPIO_DIRECTION;

typedef enum
{
	LOW = 0x00,
	HIGH = 0x01
} GPIO_MODE;


/**
 * \brief - Sets the direction of the given gpio pin.
 * 
 * \param pin		- The gpio pin
 * \param direction - The direction (INPUT/OUTPUT)
 * 
 * \return void
 */
void GPIOPinDirection(GPIO_PIN pin, GPIO_DIRECTION direction);


/**
 * \brief - Writes specified value to given gpio pin.
 * 
 * \param pin		- The gpio pin
 * \param mode		- The value (HIGH/LOW)
 * 
 * \return void
 */
void GPIOPinWrite(GPIO_PIN pin, GPIO_MODE mode);


/**
 * \brief - Returns the value of the given gpio pin.
 * 
 * \param pin		- The gpio pin
 * 
 * \return GPIO_MODE
 */
GPIO_MODE GPIOPinRead(GPIO_PIN pin);

#endif /* GPIO_DRIVER_H_ */