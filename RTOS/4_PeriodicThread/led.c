#include "led.h"
#include "stm32f4xx.h"                  // Device header

//symbolic names to represent. check the user manual, you will know the port number corresponding to the colour LED
#define RED (1U<<14)
#define BLUE (1U<<15)
#define GREEN (1U<<12)

#define RED_BIT (1U<<28)
#define BLUE_BIT (1U<<30)
#define GREEN_BIT (1U<<24)

#define GPIOD_CLOCK (1U<<3)

void LED_Init(void)
{
	//GPIOD is connected to APB1 in the RCC register
	
	RCC->AHB1ENR |= GPIOD_CLOCK;
	GPIOD->MODER |=RED_BIT|BLUE_BIT|GREEN_BIT;
}

void RED_toggle(void)		//if LOW->HIGH if HIGH->LOW
{
	GPIOD->ODR ^= RED; 	//^ is the toggle operator
}

void BLUE_toggle(void)
{
	GPIOD->ODR ^= BLUE; //^ is the toggle operator
}

void GREEN_toggle(void)
{
	GPIOD->ODR ^= GREEN; //^ is the toggle operator
}
