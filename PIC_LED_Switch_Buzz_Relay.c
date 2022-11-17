#include <p18f4550.h>
#include "vector_relocate.h"

#define SW0 PORTBbits.RB0
#define SW1 PORTBbits.RB1
#define relay PORTCbits.RC1
#define buzzer PORTCbits.RC2


void msdelay(unsigned int time)
{
	unsigned int i,j ;
	for(i=0;i<time;i++)
	for(j=0;j<710;j++);
}

void main()
{
	unsigned int i ;
	unsigned char val = 0 ;
	
	INTCON2bits.RBPU = 0 ;
	ADCON1 = 0x0F ;
	
	TRISD = 0x00 ;        // PORTD as output
	TRISBbits.RB0 = 1 ;   // Switch as input SW0
	TRISBbits.RB1 = 1 ;   // Switch as input SW1
	
	TRISCbits.RC1 = 0 ;   // Relay Output
	TRISCbits.RC2 = 0 ;   // Buzzer Output
	
	while(1)
	{
		if(SW0 == 0)
			val=1;
		if(SW1 == 0)
			val=2;
		
		if(val==1)
		{
			PORTD = 0x08 ;
			relay=1 ;  // Relay ON
			buzzer=1 ;  // Buzzer ON
			for(i=0;i<8;i++)
			{
				PORTD=PORTD>>1;
				msdelay(100) ;
			}
		}
		
		if(val==2)
		{
			PORTD = 0x00;
			relay=0 ;  // Relay OFF
			buzzer=0 ;  // Buzzer OFF
			for(i=0;i<8;i++)
			{
				PORTD=PORTD<<1 ;
				msdelay(100) ;
			}
		}
	}
}