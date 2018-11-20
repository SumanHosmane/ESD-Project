/*TRANSMIT CODE*/

#include<stdio.h>
#include<mcs51/8051.h>
#include<mcs51/8052.h>
#include<mcs51/at89c51ed2.h>
#include <reg51.h>

#define motor1 P1_6             //LEFT WHEEL
#define motor2 P1_7             //RIGHT WHEEL

#define control_pin P1_0

void serial_init()
{
    SCON = 0X50;
    TMOD = 0X20;
    TH1 = 0X0FD;
    TR1 = 1;
    TI = 1;
}

void delay(unsigned int s)
{
    int i,j;
    while(s!=0)
    {
    	for(i=0;i<65535;i++)
    	{
	    for(j=0;j<65535;j++);
    	}
	s--;
    }

}

int UART_TxChar(char ch){
	printf_tiny("\n\rCurrently in Tx function\n\r");
	SBUF=ch;           // Load transmitted data to be transmitted.
	while(TI!=0);      // Wait till data is transmitted
	TI=0;              //Clear the transmit flag.
	printf_tiny("\n\rLeaving Tx function\n\r");
	return 0;
}

unsigned char serial_read(){
        while(!RI);
        RI = 0;
        return SBUF;
}

void putchar(char c)
{
    while(!TI);
    SBUF=c;
    TI=0;
}

char getchar ()
{
    while (!RI);
	RI = 0;
	return SBUF;
}

void stop()
{
    motor1=0;
    motor2=0;
}


void main()
{
    char dir[10];
    int i, time[10];
    serial_init();
    printf_tiny("\n\rMotor driver test.\n\r");
    printf_tiny("\n\r********************************PROGRAMMABLE ROVER********************************\n\r");
    printf_tiny("\n\rPress F or f for FORWARD movement\n\r");
    printf_tiny("\n\rPress S or s for STOP movement\n\r");
    printf_tiny("\n\rPress R or r for RIGHT movement\n\r");
    printf_tiny("\n\rPress L or l for LEFT movement\n\n\n\r");
	

    printf_tiny("\n\rEnter direction and time.\n\r");
    for(i=0;i<10;i++)
    {
	    printf_tiny("\n\rEnter direction %d\n\r", i+1);
	    dir[i] = getchar();
	    putchar(dir[i]);

	    printf_tiny("\n\rEnter time %d\n\r",i+1);
	    time[i] = getchar();
	    putchar(time[i]);
    }

    printf_tiny("\n\rOutside take input\n\r");

    while(control_pin == 1);

    for(i=0;i<10;i++)
    {
        switch(dir[i])
        {
        case 'f':
	    stop();
            printf_tiny("\n\rFORWARD\n\r");
            stop();
            delay(time[i]);
            break;

        case 's':
            printf_tiny("\n\rSTOP\n\r");
	    motor1 = 0;
	    motor2 = 0;
	    delay(time[i]);
            break;

        case 'r':
			stop();
            printf_tiny("\n\rRIGHT\n\r");
            delay(time[i]);
            motor1=1;
            motor2=0;
            delay(time[i]);
            break;

        case 'l':
            stop();
	    printf_tiny("\n\rLEFT\n\r");
            motor1=0;
            motor2=1;
            delay(time[i]);
            break;

        default:
            printf_tiny("\n\rInvalid input\n\r");
            break;
        }
    }
}
