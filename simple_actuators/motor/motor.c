#include<reg51.h>
sbit mc1=P3^1;
sbit mc2=P3^2;
void ms_delay( unsigned int time);
void main()
{
	while(1)
	{
mc1=1;
mc2=0;
ms_delay(5000);
mc1=0;
mc2=1;
ms_delay(5000);	
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
