#include "led.h"
#include "stm32f4xx.h"                  // Device header
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX


void RED_thread(void const* argument)
{
	while(1)
	{
		RED_toggle();
		osDelay(100);
	}
}

void BLUE_thread(void const* argument)
{
	while(1)
	{
		BLUE_toggle();
		osDelay(100);
	}
}
void GREEN_thread(void const* argument)
{
	while(1)
	{
		GREEN_toggle();
		osDelay(100);
	}
}
//***********************************************Thread parameter definition************************************************

osThreadDef(RED_thread,osPriorityNormal,1,0);																	//normal priority, 1 instance and 0 stacksize
osThreadDef(BLUE_thread,osPriorityNormal,1,0);																//normal priority, 1 instance and 0 stacksize
osThreadDef(GREEN_thread,osPriorityNormal,1,0);																//normal priority, 1 instance and 0 stacksize

//***********************************************Driver Main Function*******************************************************
int main(void)
{
	LED_Init();
	osThreadCreate(osThread(RED_thread),NULL);
	osThreadCreate(osThread(BLUE_thread),NULL);
	osThreadCreate(osThread(GREEN_thread),NULL);
	
	while(1)
	{
	
	}
}

