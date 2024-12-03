// blink led P1

#include<reg52.h>

void ms_delay( unsigned int time);

void main()
{
	
	while(1)
	{
	P1=0x0ff;  //on led
	ms_delay(1000);// delay 1s
	P1=0x00; // off led
	ms_delay(1000);
	}
	
}

void ms_delay( unsigned int time)
{
	unsigned int i,j;
	//time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);  //1 ms
	}
}