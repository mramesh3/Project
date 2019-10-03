//PF4 GPIO SW1
//PF0 GPIO SW2
//PF1 GPIO RGB LED (Red)
//PF2 GPIO RGB LED (Blue)
//PF3 GPIO RGB LED (Green)

#include "TM4C123.h"                    // Device header
//#define BLUE (1U<<2);
// //Program for red blinking
//void delayMS(int ms);
//int main()
//{
//SYSCTL->RCGCGPIO |= 0x20;
//GPIOF->DIR	|=0x0A;
//GPIOF->DEN	|=0x0A;
//GPIOF->DATA |=0x00;
//	while(1)
//	{
//		GPIOF->DATA |=0x02;
//		delayMS(5000);
//		GPIOF->DATA &=~0x02;
//		delayMS(5000);
//		GPIOF->DATA |=0x08;
//		delayMS(5000);
//		GPIOF->DATA &=~0x08;
//		delayMS(5000);
//		
//	}
//}

//void delayMS(int ms)
//{
//	int i,j;
//	for(i=0;i<ms;i++)
//		{
//			for(j=0;j<3180;j++)
//				{
//			 
//				}
//		}
//}

////program for green blink from switch input
//int main()
//{
//SYSCTL->RCGCGPIO |=0x20;
//GPIOF->DIR |=0x08; 
//GPIOF->DEN |=0x18;
//GPIOF->PUR |=0x10;
//	
//	while(1)
//	{
//		if(!(GPIOF->DATA &0x10))
//		{
//			GPIOF->DATA |= 0x08;
//		}
//		else
//		{
//			GPIOF->DATA  &=~0x08;
//		}
//	}
//}


//program with red green blink with blue switch input

//int main()
//{
//	SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR |=0x0E;
//	GPIOF->DEN |=0x1E;
//	GPIOF->PUR |=0x10;
//	
//	while(1)
//	{
//   	GPIOF->DATA |=0x02;
//		delayMS(2000);
//		GPIOF->DATA &=~0x02;
//		delayMS(1000);
//		GPIOF->DATA |=0x08;
//		delayMS(2000);
//		GPIOF->DATA &=~0x08;
//		delayMS(1000);
//		
//		if(!(GPIOF->DATA &0x10))
//		{
//			GPIOF->DATA |= 0x08;
//		}
//		else
//		{
//			GPIOF->DATA  &=~0x08;
//		}
//	}
//		
//}

//void delayMS(int ms)
//{
//	int i,j;
//	for(i=0;i<ms;i++)
//		{
//			for(j=0;j<3180;j++)
//				{
//			 
//				}
//		}
//}

//toggle LED at 1HZ using systick timer

//int main()
//{
//  SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR = 0x0E;
//	GPIOF->DEN = 0x0E;
//	
//	//SYSTICK CONFIG
//	SysTick->LOAD = 16000000-1;
//	SysTick->CTRL = 5; //enable systick, no interrupt, use system clock
//	
//	while(1)
//	{
//	
//		if(SysTick->CTRL &0x10000)
//		{
//			GPIOF->DATA^=2;
//		}
//	}
//}

////timer driver one shot
//void timerA0DelayMs(int delay);
//int main()
//{
//  SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR = 0x0E;
//	GPIOF->DEN = 0x0E;
//	
//	while(1)
//	{
//		GPIOF->DATA^=2;
//		timerA0DelayMs(5000);
//	}
//}

//void timerA0DelayMs(int delay)
//{
//	SYSCTL->RCGCTIMER |=1; 		//Enable clock for timer block 0
//	TIMER0->CTL =0; 					//disable the timer before start of configuration
//	TIMER0->CFG =0x04;				//timer mode is 16 bit mode
//	TIMER0->TAMR=0x01;				//one shot mode, down counter
//	//need to access timer interval load register interval decides the delay amount
//	
//	TIMER0->TAILR=16000*delay-1;  //in millisec, dependent on the clock frequency. in this case is 16Mhz
//	TIMER0->ICR=0x01;		//clear timerA timeout flag
//	TIMER0->CTL |=0x01;	//enable timer
//	
//	//Access ris register to wait for timeout flag to set
//	
//	while((TIMER0->RIS & 0x1)==0)
//	{
//	
//	}
//}

// timer in periodic mode
//void timerA0DelayMs(int delay);
//int main()
//{
//  SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR = 0x0E;
//	GPIOF->DEN = 0x0E;
//	
//	while(1)
//	{
//		GPIOF->DATA^=2;
//		timerA0DelayMs(500);
//	}
//}

//void timerA0DelayMs(int delay)
//{
//	SYSCTL->RCGCTIMER |=1; 		//Enable clock for timer block 0
//	TIMER0->CTL =0; 					//disable the timer before start of configuration
//	TIMER0->CFG =0x04;				//timer mode is 16 bit mode
//	TIMER0->TAMR=0x02;				//one shot mode, down counter
//	//need to access timer interval load register interval decides the delay amount
//	
//	TIMER0->TAILR=16000-1;  //in millisec, dependent on the clock frequency. in this case is 16Mhz
//	TIMER0->ICR=0x01;		//clear timerA timeout flag
//	TIMER0->CTL |=0x01;	//enable timer
//	
//	//Access ris register to wait for timeout flag to set
//	
//for (int i=0;i<delay;i++){
//	while((TIMER0->RIS &0x1)==0) {}
//		TIMER0->ICR=0x1;
//}
//}

////working with timer B

//void timerB0DelayMs(int delay);
//int main()
//{
//  SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR = 0x0E;
//	GPIOF->DEN = 0x0E;
//	
//	while(1)
//	{
//		GPIOF->DATA^=2;
//		timerB0DelayMs(5000);
//	}
//}

//void timerB0DelayMs(int delay)
//{
//	SYSCTL->RCGCTIMER |=1; 		//Enable clock for timer block 0
//	TIMER0->CTL =0; 					//disable the timer before start of configuration
//	TIMER0->CFG =0x04;				//timer mode is 16 bit mode
//	TIMER0->TBMR=0x02;				//periodic mode
//	//need to access timer interval load register interval decides the delay amount
//	
//	TIMER0->TBILR=16000-1;  //in millisec, dependent on the clock frequency. in this case is 16Mhz
//	TIMER0->ICR=0x100;		//clear timerB timeout flag
//	TIMER0->CTL |=0x100;	//enable timer
//	
//	//Access ris register to wait for timeout flag to set
//	
//for (int i=0;i<delay;i++){
//	while((TIMER0->RIS &0x100)==0) {}
//		TIMER0->ICR=0x100;
//}
//}


// timer using prescaler
//void timerA1DelayMs(int delay);
//int main()
//{
//  SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR = 0x0E;
//	GPIOF->DEN = 0x0E;
//	
//	while(1)
//	{
//		GPIOF->DATA^=2;
//		timerA1DelayMs(5);
//	}
//}

//void timerA1DelayMs(int delay)
//{
//	SYSCTL->RCGCTIMER |=0x02; 		//Enable clock for timer block 1 
//	TIMER1->CTL =0; 					//disable the timer before start of configuration
//	TIMER1->CFG =0x04;				//timer mode is 16 bit mode
//	TIMER1->TAMR=0x02;				//periodic mode, down counter
//	//need to access timer interval load register interval decides the delay amount
//	
//	// ex: 250 in prescaler
//	//16000000/250=64000Hz is the timmers clock frequency	
//	//1/64000 Hz=15.6ms -> one single cycle
//	
//	TIMER1->TAILR=64000-1;  //in millisec, dependent on the clock frequency. in this case is 16Mhz
//	TIMER1->TAPR=250-1; //prescaler value
//	TIMER1->ICR=0x01;		//clear timerA timeout flag
//	TIMER1->CTL |=0x01;	//enable timer
//	
//	//Access ris register to wait for timeout flag to set
//	
//for (int i=0;i<delay;i++){
//	while((TIMER1->RIS &0x1)==0) {}
//		TIMER1->ICR=0x1;
//}
//}

//Progrm for 16/32 bit timer use

//void delaySecond(uint32_t sec);
//int main()
//{
//	SYSCTL->RCGCGPIO |=(1U<<5);
//	GPIOF->DIR |=BLUE;
//	GPIOF->DEN |=BLUE;
//	
//	while(1)
//	{
//		GPIOF->DATA ^=BLUE;
//		delaySecond(10);
//	}
//	
//}

//void delaySecond(uint32_t sec)
//{
//	SYSCTL->RCGCTIMER |=0x01;
//	TIMER0->CTL=0x00;	//disable timer 0 during setup
//	TIMER0->CFG = 0;	//configure for 32 bit timer
//	TIMER0->TAMR=0x02;
//	TIMER0->TAILR=16000000-1;
//	TIMER0->ICR=0x01;
//	TIMER0->CTL |=0x01;
//	for (int j=0;j<sec;j++)
//	{
//		while((TIMER0->RIS &0x1)==0) {}
//		TIMER0->ICR=0x01;
//	}
//}

//Systick interrupt

//int main()
//{
//	SYSCTL->RCGCGPIO |=0x20;
//	GPIOF->DIR |=0x0E;
//	GPIOF->DEN |=0x0E;
//	//configure the systick
//	__disable_irq();  //disable the interrupt globally
//	SysTick->LOAD = 16000000-1;
//	SysTick->CTRL=7; //enable the systick use interrupt and use system clock
//	
//	__enable_irq();
//	
//	while(1){}		//the blinking will happen in the systick function
//}

//void SysTick_Handler()
//{
//	//FIR or DSP filters 
//GPIOF->DATA^=0x02;	
//}

//GPIO interrupt 
//unresolved doubts. the output is not as depicted
//int main()
//{
//	SYSCTL->RCGCGPIO |=0x20;
//	//unlocking the register PF0
//	GPIOF->LOCK = 0x4C4F434B;
//	GPIOF->CR =0x01;
//	GPIOF->LOCK =0;
//	
//	//configure port f for switch and LED
//	
//	GPIOF->DIR &=~11;		//make PF4 and PF0 input pins
//	GPIOF->DIR |=0x0E;
//	GPIOF->DEN|=0x1F;
//	GPIOF->PUR |=0x11; 	//enabling the pull up register for PF4 and PF0
//	__disable_irq();
//	//faling edge trigger interrupt
//	GPIOF->IS &=~0x11;			//make PF4 and pf0 edge sensitive
//	GPIOF->IBE &=~0x11;
//	GPIOF->IEV &=~0x11;		//falling edge detection
//  GPIOF->	ICR |=0x11;		//clear any prior interrupts
//	GPIOF->IM |=0x11;		//unmask interrupt
//	
//	NVIC->IP[30] =3<<5;	//priority of interrupt is set to 3
//	NVIC->ISER[0]=0x40000000;	//enable IRQ30
//	__enable_irq();
//	while(1){
//		//toggle red LED
//		GPIOF->DATA |=0x02;
//		delayMs(100);
//		GPIOF->DATA &=~0x02;
//		delayMs(100);
//	}
//		
//}

//void GPIOF_Handler(void)
//{
//	volatile int readback;
////toggle green LED
//	for(int i=0;i<3;i++)
//	{
//		GPIOF->DATA |=0x08;
//		delayMs(100);
//		GPIOF->DATA |=~0x08;
//		delayMs(100);
//	}
//	GPIOF->ICR |=0x11;		//clear interrupt flag before return
//	readback=GPIOF->ICR;
//	
//}

//void delayMs(int delay)
//{
//	for (int i=0;i<delay;i++)
//	{
//		for(int j=0;j<3180;j++)
//		{}
//	}
//}

//multiple gpio inputs


//GPIO interrupt 
//unresolved doubts. the output is not as depicted
//int main()
//{
//	SYSCTL->RCGCGPIO |=0x20;
//	//unlocking the register PF0
//	GPIOF->LOCK = 0x4C4F434B;
//	GPIOF->CR =0x01;
//	GPIOF->LOCK =0;
//	
//	//configure port f for switch and LED
//	
//	GPIOF->DIR &=~11;		//make PF4 and PF0 input pins
//	GPIOF->DIR |=0x0E;
//	GPIOF->DEN|=0x1F;
//	GPIOF->PUR |=0x11; 	//enabling the pull up register for PF4 and PF0
//	__disable_irq();
//	//faling edge trigger interrupt
//	GPIOF->IS &=~0x11;			//make PF4 and pf0 edge sensitive
//	GPIOF->IBE &=~0x11;
//	GPIOF->IEV &=~0x11;		//falling edge detection
//  GPIOF->	ICR |=0x11;		//clear any prior interrupts
//	GPIOF->IM |=0x11;		//unmask interrupt
//	
//	NVIC->IP[30] =3<<5;	//priority of interrupt is set to 3
//	NVIC->ISER[0]=0x40000000;	//enable IRQ30
//	__enable_irq();
//	while(1){
//		//toggle red LED
//		GPIOF->DATA |=0x02;
//		delayMs(100);
//		GPIOF->DATA &=~0x02;
//		delayMs(100);
//	}
//		
//}

//void GPIOF_Handler(void)
//{
//	volatile int readback;
////toggle green LED

//	while(GPIOF->MIS!=0)
//	{
//		if(GPIOF->MIS & 0x10)	//check if Sw1 is true or not
//		{
//				for(int i=0;i<3;i++)
//	{
//		GPIOF->DATA |=0x08;
//		delayMs(100);
//		GPIOF->DATA |=~0x08;
//		delayMs(100);
//	}
//	GPIOF->ICR |=0x11;		//clear interrupt flag before return
//	readback=GPIOF->ICR;
//		}
//		else if(GPIOF->MIS & 0x01)	//check for switch 2
//		{
//			for(int i=0;i<3;i++)
//	{
//		GPIOF->DATA |=0x08;
//		delayMs(100);
//		GPIOF->DATA |=~0x08;
//		delayMs(100);
//	}
//	GPIOF->ICR |=0x11;		//clear interrupt flag before return
//	readback=GPIOF->ICR;
//		}
//		
//		else{
//			GPIOF->ICR=GPIOF->MIS;
//			readback = GPIOF->ICR;
//		}
//	}
//}

//void delayMs(int delay)
//{
//	for (int i=0;i<delay;i++)
//	{
//		for(int j=0;j<3180;j++)
//		{}
//	}
//}

//32 bit Timer

//ADC driver
//int result;
//int main()
//{
//	SYSCTL->RCGCGPIO |=0x10; //enable clock for port e
//	SYSCTL->RCGCADC |=0x01; 	//enable clock for ADC module 0
//	
//	//PE 3 init
//	GPIOE->AFSEL |=8;  // enable alternate function
//	GPIOE->DEN  &=~8;	//disable digital function
//	GPIOE->AMSEL |=8;	//enable analog function 
//	
//	//ADC init
//	ADC0->ACTSS &=~8;	//disable sample sequencer 3(SS3)
//	ADC0->EMUX &=~0xF000;	// software trigger conversion
//	ADC0->SSMUX3=0;				//get input from channel 0
//	ADC0->SSCTL3 |=6;			//take one sample at a time, set flag at 1st sample
//	ADC0->ACTSS |=8;			//enable ss3
//	
//	while(1)
//	{
//		ADC0->PSSI |=8;			//Start a converstion at ss3
//		while((ADC0->RIS&8)==0)		//wait for conversion complete
//		{}
//			result=ADC0->SSFIFO3;
//			ADC0->ISC =8;
//	}
//	
//}

//ADC temperature sensor

//volatile int temperature;
//int main()
//{
//	SYSCTL-> RCGCADC |=0x01;
//	SYSCTL->RCGCWTIMER  |=0x01;
//	
//	//ADC init
//	ADC0->ACTSS &=~0x8;
//	ADC0->EMUX &=~0xF000;
//	ADC0->EMUX |=0x5000;		//timer trigger conversion sequence 0
//	ADC0->SSMUX3 =0;
//	ADC0->SSCTL3 =0x0E; 	// take MCU temperature, set flag at 1st sample
//	ADC0->ACTSS |=0x8;
//	
//	//WTimer Init
//	
//	WTIMER0->CTL =0;
//	WTIMER0->CFG=0x04;		// to select 32 bit option
//	WTIMER0->TAMR=0x02;	// periodic mode and down counter mode 
//	WTIMER0->TAILR =16000000;
//	WTIMER0->CTL |=0x20;
//	WTIMER0->CTL |=0x01;
//	
//	while(1)
//	{
//		while((ADC0->RIS &8)==0)
//		{}
//		temperature=147-(247*ADC0->SSFIFO3)/4096;
//			ADC0->ISC=8;		//clear completion flag
//			
//	}
//}


//Interrupt handler

#define GREEN	(1U<<3)
#define RED	(1U<<2)
#define BLUE (1U<<4)

void timer1A_1Hz_init(void);
void timer2A_10HZ_init(void);
int main(void)
{
	SYSCTL-> RCGCGPIO |=0x20;
	GPIOF->DIR=0x0E;
	GPIOF->DEN=0x0E;
	timer1A_1Hz_init();
	timer2A_10HZ_init();
	__enable_irq();
	
	while(1)
	{
	GPIOF->DATA^=BLUE;
	}
}

//to create timer interrupts
void timer1A_1Hz_init(void)
{
	SYSCTL->RCGCTIMER |=0x02;	//enable clock to timer block 1
	TIMER1->CTL =0; 					//disable timer1 before initialization
	TIMER1->CFG =0x04;				//16 bit option
	TIMER1->TAMR =0x02;				//periodic mode and down counter
	TIMER1->TAPR=250;					//16000000hz/250=64000hz
	TIMER1->TAILR=64000;		//64000hz/64000=1hz
	TIMER1->ICR=0x01;				//clear timer 1A timeout flag
	TIMER1->IMR |=0x01;		//interrupt mask register- enable timer 1A timeout
	TIMER1->CTL |=0x01;		//enable timer1A after initialization
	NVIC->ISER[0] |=0x00200000;		//enable IRQ21 (D21 of ISER[0]) nested vector interrupt controller
}

void timer2A_10HZ_init(void)
{
 SYSCTL->RCGCTIMER |=0x04;
	TIMER2->CTL =0;
	TIMER2->CFG =0x04;
	TIMER2->TAMR =0x02;
	TIMER2->TAPR=250;		//timer1A_1Hz_init prescaler
	TIMER2->TAILR=6400;
	TIMER2->ICR=0x01;	
	TIMER2->IMR |=0x01;	
	TIMER2->CTL |=0x01;
	NVIC->ISER[0] |=0x00800000; 		// IRQ23(D23 of ISER[0])
}

void TIMER1A_Handler(void)
{
	volatile int clear;
	if(TIMER1->MIS & 0x1)
	{
		GPIOF->DATA^=RED;
		TIMER1->ICR=0x1;
		clear=TIMER1->ICR;
	}
	else{
		TIMER1->ICR=TIMER1->MIS;		//clear all flags
		clear=TIMER1->ICR;		//force clearing in case prev statement isnt executed
	}
}

void TIMER2A_Handler(void)
{
volatile int clear;
	if(TIMER2->MIS & 0x1)
	{
		GPIOF->DATA^=GREEN;
		TIMER2->ICR=0x1;
		clear=TIMER2->ICR;
	}
	else{
		TIMER2->ICR=TIMER2->MIS;		//clear all flags
		clear=TIMER2->ICR;		//force clearing in case prev statement isnt executed
	}
}