#include <reg51.h>

void delay(unsigned int) ;

void main()
{
	unsigned char index = 0 ;
	P2 = 0 ;
	while(1)
	{
		unsigned int i,j ;
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				P2 = (i<<4)|j ;
				delay(1000) ;
			}
			index = index<<1 ;
		}
	}
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}