#include<stdio.h>
#include<mcs51/8051.h>
#include<mcs51/8052.h>
#include<mcs51/at89c51ed2.h>
#include <reg51.h>

#define motor1 P1_6             //LEFT WHEEL
#define motor2 P1_7             //RIGHT WHEEL
#define led P1_2

char getchar ()
{
    while (!RI);
	RI = 0;
	return SBUF;
}

void putchar(char c)
{
    while(!TI);
    SBUF=c;
    TI=0;
}

void delay()
{
    unsigned int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++);
    }
}


void serial_init()
{
    SCON = 0X50;
    TMOD = 0X20;
    TH1 = 0X0FD;
    TR1 = 1;
    TI = 1;
}

char UART_RxChar()
{
	while(RI!=0);
	RI=0;
	return SBUF;
}

int UART_TxChar(char ch){
	printf_tiny("\n\rCurrently in Tx function\n\r");
	SBUF=ch;           // Load transmitted data to be transmitted.
	while(TI!=0);      // Wait till data is transmitted
	TI=0;              //Clear the transmit flag.
	printf_tiny("\n\rLeaving Tx function\n\r");
	return 0;
}

void main()
{
    char rc;
	serial_init();
    printf_tiny("\n\rIN MAIN\n\r");

    rc = UART_RxChar();
    delay();
	putchar(rc);

    //rc=getchar();
    //putchar(rc);
	//UART_TxChar(rc);

    if(rc == '1')
	{
	    printf_tiny("\n\rled=1\n\r");
		led = 1;
		main();
	}

	else if(rc=='0')
	{
	    printf_tiny("\n\rled=0\n\r");
		led= 0;
		main();
	}
	else
    {

        printf_tiny("\n\rInvalid input\n\r");
        main();
    }
}

