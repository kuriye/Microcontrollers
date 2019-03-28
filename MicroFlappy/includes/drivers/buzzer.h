/*
 * buzzer.h
 *
 * Created: 20/03/2019 09:15:40
 *  Author: Carlos Cadel
 */ 

#ifndef EASYBUZZ_H_
#define EASYBUZZ_H_


void BuzzerInit();

void BuzzerSetFrequency(int frequency);
void BuzzerPwmOff();

#endif /* EASYBUZZ_H_ */