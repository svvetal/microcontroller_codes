#include <reg51.h>
void delay(unsigned int);

void main()
{
	unsigned int x ;
	P1 = 0 ;
	while(1)
	{
		for(x=0;x<255;x++)
		{
			delay(10) ;
			P1 = x ;
		}
		for(x=255;x>=0;x--)
		{
			delay(10) ;
			P1 = x ;
		}
	}
}

void delay(unsigned int time)
{
	unsigned int i,j ;
	for (i=0;i<time;i++)
	for(j=0;j<1275;j++);
}