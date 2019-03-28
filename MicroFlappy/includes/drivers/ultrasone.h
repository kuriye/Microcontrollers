/*
 * ultrasone.h
 *
 * Created: 27/03/2019 15:23:09
 *  Author: Bou's Laptop
 */ 


#ifndef ULTRASONE_H_
#define ULTRASONE_H_

#define  Distance(time)			(time/58)

void Ultrasonicinit();
void Trigger();
void Echo();


#endif /* ULTRASONE_H_ */