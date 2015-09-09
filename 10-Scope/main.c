#include "USART.h"

void Delay( uint32_t nCount) 
{
		while(nCount--) {
		}
}

void ms_delay(int ms)
{
		while (ms-- > 0) 
		{
				volatile int x=5971;
				while (x-- > 0)
						asm("nop");
		}
}


int main(void)
{
		char buffer[100];
		int i=150;
		initUSART();
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;  // enable the clock to GPIOD
		GPIOD->MODER = (1 << 26);             // set pin 13 to be general purpose output
		GPIOD->MODER |= (1 << 24);
		GPIOD->MODER |= (1 << 28);
		GPIOD->MODER |= (1 << 30);
		while(1){
				printString("another pretty day is started ! \r\nwhat do u want ? \r\n");
				readString(buffer,100);
				if( buffer == "go to hell"){
						printString("\r\nshut up ... \r\n");
				}
				else {
						printString("\r\nerror in input command\r\n");
				}
		}
}
