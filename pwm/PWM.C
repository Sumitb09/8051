// blink led P1

#include<reg52.h>

void ms_delay( unsigned int time);

void main()
{
	int x;
	
	while(1)
	{
	for(x=0;x<=200;x++)
	{
	P1=0x0ff;  //on led
		P3=(0x01<<5);  //on motor
	ms_delay(1);// delay 1s
	P1=0x00; // off led
	P3=0x00;  //off motor
	ms_delay(9);
	}
	
		for(x=0;x<=200;x++)
	{
	P1=0x0ff;  //on led
		P3=(0x01<<5);  //on motor
	ms_delay(5);// delay 1s
	P1=0x00; // off led
		P3=0x00;  //off motor
	ms_delay(5);
	}
	
		for(x=0;x<=200;x++)
	{
	P1=0x0ff;  //on led
		P3=(0x01<<5);  //on motor
	ms_delay(9);// delay 1s
	P1=0x00; // off led
		P3=0x00;  //off motor
	ms_delay(1);
	}
	

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