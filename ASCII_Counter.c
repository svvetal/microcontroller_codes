#include <reg51.h>

void delay(unsigned int) ;

void main()
{
	P3 = 0 ;
	while(1)
	{
		int x = 0 ;
		for(x='A';x<'Z';x++)
		{
			P3 = x ;
			delay(1000) ;
		}
	}
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}