//Header interface file for LED driver main function

#ifndef __LED_H
#define __LED_H
#include "stm32f4xx.h"                  // Device header


void LED_Init(void);
void RED_toggle(void);
void BLUE_toggle(void);
void GREEN_toggle(void);

#endif

