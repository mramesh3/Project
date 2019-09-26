#include "LED.h"                    // Device header
#include "stm32f4xx.h"                  // Device header


//ports which controls the LED'scan be referred from the manual

#define RED (1U<<14)
#define BLUE (1U<<15)
#define GREEN (1U<<12)

//identify the register which controls the LED's in user manual

#define RED_BIT (1U<<28)
#define GREEN_BIT (1U<<24)
#define BLUE_BIT (1U<<30)

//defining the clock for port D 
#define GPIO_CLOCK (1U<<3)


void led_init(void)
{
	RCC->AHB1ENR |=GPIO_CLOCK;
	GPIOD->MODER |=RED_BIT|GREEN_BIT|BLUE_BIT;		//set the mode register fo LED output
	
}

void RED_toggle(void)
{
	GPIOD->ODR^=RED;
}

void BLUE_toggle(void)
{
	GPIOD->ODR^=BLUE;
}

void GREEN_toggle(void)
{
	GPIOD->ODR^=GREEN;
}

