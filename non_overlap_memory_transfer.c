#include <reg51.h>

void main()
{
	unsigned char *desc , *src ;
	unsigned int x ;
	
	src = 0x20 ;
	desc = 0x40 ;
	
	for (x=0;x<=10;x++)
	{
		*desc = *src ;
		src++ ;
		desc++ ;
	}
}