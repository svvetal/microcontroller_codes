#include <reg51.h>

void main()
{
	unsigned char *src , *desc ;
	unsigned int x ;
	
	src = 0x29 ;
	desc = 0x2e ;
	
	for (x=0;x<=10;x++)
	{
		*desc = *src ;
		desc-- ;
		src-- ;
	}
}