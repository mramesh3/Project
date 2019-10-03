//Topic: Creating a simple thread management system

//Author: Mahendri

#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "TM4C123.h"                    // Device header

int32_t count1,count2,count3; 					// to check and debug for threads
			
//Creating the thread definition

void thread1(void const *argument)
{
	while(1)
	{
		++count1;
	}
}

void thread2(void const *argument)
{
	while(1)
	{
		++count2;
	}
}

void thread3(void const *argument)
{
	while(1)
	{
		++count3;
	}
}


//threaddef to define the thread with priority(normal) and number of 
//instance=1

osThreadDef(thread1,osPriorityNormal,1,0);				//0-default stack size
osThreadDef(thread2,osPriorityNormal,1,0);
osThreadDef(thread3,osPriorityNormal,1,0);

//creating the main function with parameters to manage thread: 
int main(void)
{
	//creating the thread
	
	osThreadCreate(osThread(thread1),NULL);
	osThreadCreate(osThread(thread2),NULL);
	osThreadCreate(osThread(thread3),NULL);
	
	while(1)																				//infinite loop
	{
	
	}
}
