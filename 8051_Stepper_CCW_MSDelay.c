#include <reg51.h>

void delay(unsigned int);

void main()
{
	int coil[4] = {0x09,0x0c,0x06,0x03};
	unsigned int i ;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			P0 = coil[i] ;
			delay(1000) ;
		}
	}
}

void delay(unsigned int time)
{
	unsigned int i,j ;
	for (i=0;i<time;i++)
	for(j=0;j<1275;j++);
}