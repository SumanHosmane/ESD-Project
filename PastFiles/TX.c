#include <REGx051.H>
#include <REGX52.H>
#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <8052.h>
#include <stdio.h>

//-------------FUNCTION DECLARATION-------------------------------//
void UART_Init();
void UART_TxChar(char ch);
void transmit(int datum);
void delay(int delay);

struct parameters
{
	char direction;
	int seconds;
};
 
void main()
{ 
	while(1)
	{
		struct parameters p;
		printf("\r");
		printf("Enter the direction:\n\r");
		p.direction = getchar();
		putchar(p.direction);
		printf("Enter length of travel(in seconds):\n\r");
		p.seconds = getchar();
		putchar(p.seconds);
		
	//EA = 0;
	
	UART_Init();

	transmit(p.direction);
	delay(1000);
	delay(1000);
	transmit(p.seconds);
	}
}
 


//---------------FUNCTIONS--------------------------------------

void delay(int s)
{
	while(s!=0)
	{
		 unsigned int j, s;
		 for(j=0;j<1257;j++);  // for 1ms delay
		 s=s-1;
	}
}

	
	void UART_Init()
	{
		TMOD |= 0X20;                       // Timer 1 in mode 2 
		TH1=-24;                            // Baud rate of 1200
		SCON = 0X50;                         //Asynchronous 8-bit data 
		TR1 = 1;                             // Turn ON the timer
    }

  void UART_TxChar(char ch)
  {
	SBUF=ch;           // Load transmitted data to be transmitted.
	while(TI==0);      // Wait till data is transmitted
	TI=0;              //Clear the transmit flag.
  }

void transmit(int txdata)
{	
	//int start  =  0x55;             // Create a variable name START
	//int addr   =  0x8E;              //  Create a variable name ADDR  
	//int chksum =  (addr+datum);            //   Create a variable name CHKSUM
		
	//UART_TxChar(start);           // Transmit the content of START
	UART_TxChar(txdata);           // Transmit DATUM
	//UART_TxChar(addr);            //Transmit ADDR
	//UART_TxChar(chksum);          // Transmit CHKSUM
	delay(500);
}
	
	