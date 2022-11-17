#include <reg51.h>

void delay(unsigned int);

void main()
{
	
	
	int a[13]={128,192,238,254,238,192,128,64,17,0,17,64,128} ;
	unsigned int k;
	
	while(1)
	{
		for(k=0;k<13;k++)
		{
			delay(10) ;
			P1 = a[k] ;
		}
	}
}

void delay(unsigned int time)
{
	unsigned int i,j ;
	for (i=0;i<time;i++)
	for(j=0;j<1275;j++);
}

