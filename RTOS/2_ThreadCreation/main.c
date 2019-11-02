/* 

Topic: RTOS Thread creation
Author: Mahendri Ramesh

Notes: 
Target settings: Operating frequency: 16MHz
Debugger: ST-Link with reset and run enabled
using with simulator
*/

//***********************************************Project Setup files********************************************************

#include "stm32f4xx.h"                  // Device header
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX

//***********************************************Global variables*************************************************

int32_t count1, count2,count3;

//***********************************************Thread function definition*************************************************

void thread1(void const* argument)
{
	while(1)
	{
		++count1;
	}
}

void thread2(void const* argument)
{
	while(1)
	{
		++count2;
	}
}
void thread3(void const* argument)
{
	while(1)
	{
		++count3;
	}
}
//***********************************************Thread parameter definition************************************************

osThreadDef(thread1,osPriorityNormal,1,0);																	//normal priority, 1 instance and 0 stacksize
osThreadDef(thread2,osPriorityNormal,1,0);																	//normal priority, 1 instance and 0 stacksize
osThreadDef(thread3,osPriorityNormal,1,0);																	//normal priority, 1 instance and 0 stacksize

//***********************************************Driver Main Function*******************************************************
int main(void)
{
	osThreadCreate(osThread(thread1),NULL);
	osThreadCreate(osThread(thread2),NULL);
	osThreadCreate(osThread(thread3),NULL);
	
	while(1)
	{
	
	}
}

