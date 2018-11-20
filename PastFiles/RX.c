#include <REGX52.H>
#include <at89c51ed2.h>
#include <mcs51reg.h>
#include <8052.h>
#include <stdio.h>

#define LEFT P1.5
#define RIGHT P1.6


//-------------FUNCTION DECLARATION------------------------------- 
void UART_Init();
char UART_RxChar();
void receive();
void delay();
int movement(char data, int seconds);
void right();
void left();
void straight(int sec);

 
//-------------MAIN PROGRAM STARTS HERE---------------------------- 
void main()
{ 

	UART_Init();

	while(1)
	{
		receive();
	}
}


//---------------FUNCTIONS----------------------------------


void delay(int s)
{
	while(s!=0)
	{
		 unsigned int j, s;
		 for(j=0;j<1257;j++);  // for 1ms delay
		 s=s-1;
	}
}

void UART_Init(){
	TMOD |= 0X20;                       // Timer 1 in mode 2 
	TH1=-24;                            // Baud rate of 1200
	SCON = 0X50;                         //Asynchronous 8-bit data 
	TR1 = 1;                             // Turn ON the timer
                }
	
	
	
	char UART_RxChar()
{	
	char ch;
	while(RI==0);
	ch = SBUF;
  	RI=0;
	  return(ch);             // Return the received character.
}



 void receive()                   //   Receive procedures
	{
//int start;	 	// create variable named start              
//int addr;   	// create variable named addr
int data;		// create variable named datum
char direction;  
int seconds;             
//int chksum; 	// create variable named chksum

while(1)               // Do an infinite loop
{
    { 
  		 SBUF =0;                              //clear SBUF
		 data = UART_RxChar();			          //received byte becomes the data
		 direction = data;
		 SBUF = 0;
		 delay(1000);
		 seconds = UART_RxChar();

		movement(data, seconds);
	}
}

int movement(char direction, int seconds)
{
	if(direction == 'f')
	{
		straight(seconds);
	}
	
	if(direction == 'r')
	{
		right();
		straight(seconds * 1000);
	}
	
	if(direction == 'l')
	{
		left();
		straight(seconds * 1000);
	}
}

void right()
{
	P1.5 = 0xFF;
	P1.6 = 0x00;
	delay(1000);
	P1.5 = 0x00;
	P1.6 = 0x00;
	return;
}
	
void left()
{
	P1.5 = 0x00;
	P1.6 = 0xFF;
	delay(1000);
	P1.5 = 0x00;
	P1.6 = 0x00;
	return;	
}

void straight(int sec)
{
	P1.5 = 0xFF;
	P1.6 = 0x00;
	delay(sec * 1000);
	P1.5 = 0x00;
	P1.6 = 0x00;
	return;
}

