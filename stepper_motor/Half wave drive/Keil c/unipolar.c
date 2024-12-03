#include<reg52.h>
void ms_delay( unsigned int time);
void main()
{
	while(1)
	{
	P2=0x08;  
	ms_delay(1000);// delay 1s
	P2=0x0C; 
	ms_delay(1000);
	P2=0x04;  
	ms_delay(1000);// delay 1s
	P2=0x06; 
	ms_delay(1000);
	P2=0x02;  
	ms_delay(1000);// delay 1s
	P2=0x03; 
	ms_delay(1000);
	P2=0x01;  
	ms_delay(1000);// delay 1s
	P2=0x09; 
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
