#include <reg51.h>

void tdelay()
{
	TMOD = 0x10 ;
	TL1 = 0x00 ;
	TH1 = 0x0DC ;
	TR1 = 0x01 ;
	while(TF1==0);
	TR1 = 0x00 ;
	TF1 = 0x00 ;
	
}

void main()
{
	int coil[4] = {0x09,0x0c,0x06,0x03};
	unsigned int i ;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			P0 = coil[i] ;
			tdelay() ;
		}
	}
}
	