// Beep buzzer

#include<reg52.h>

sbit SW=P1^0;                  // Pushbutton
sbit buzzer=P1^1;              // Buzzer

void ms_delay( unsigned int time);

void main()
{
	SW = 1;
	buzzer = 0;
	
	while(1)
	{
		if (SW == 0)            // Beep buzzer 3 times
		{
			buzzer=1;  //on Buzzer
			ms_delay(1000);// delay 1s
			buzzer=0; // off Buzzer
			ms_delay(1000);
			buzzer=1;  //on Buzzer
			ms_delay(1000);// delay 1s
			buzzer=0; // off Buzzer
			ms_delay(1000);// delay 1s
			buzzer=1; // on Buzzer
			ms_delay(1000); // delay 1s
			buzzer=0; // off Buzzer
			ms_delay(1000); // delay 1s
		}
		else
		{
			buzzer=0; // off Buzzer
		}
	}
	
}

void ms_delay( unsigned int time)    //generation of delay
{
	unsigned int i,j;
	//time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);  //1 ms
	}
}