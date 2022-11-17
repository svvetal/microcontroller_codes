#include <reg51.h>
void delay(unsigned int) ;
void main()
{
	P1 = 0 ;
	while(1)
	{
		int x = 0 ;
		for(x=0;x<255;x++)
		{
			P1 = x ;
			delay(1000) ;
		}
	}
}

void delay(unsigned int time)
{
	unsigned int i,j ;
	for (i=0;i<time;i++)
	for (j=0;j<1275;j++);
}