#include <p18f4550.h>
#include "vector_relocate.h"

void msdelay(unsigned int time)
{
	unsigned int i,j ;
	for(i=0;i<time;i++)
	for(j=0;j<710;j++);
}

void main()
{
	TRISCbits.TRISC2 = 0 ; // PORTC2 as output
	TRISD = 0 ;            // PORTD as output
	PR2 = 0xBB ;           // calculated
	CCP1CON = 0x0C ;       // configure CCP1CON
	T2CON = 0x07 ;         // PWM mode
	
	PORTDbits.RD5 = 1 ;
	PORTDbits.RD6 = 0 ;
	
	while(1)
	{
		// 100% Duty Cycle
		CCPR1L = 187 ; 
		CCP1CONbits.DC1B0 = 0 ;
		CCP1CONbits.DC1B1 = 0 ;
		msdelay(3000) ;
		
		// 80% Duty Cycle
		CCPR1L = 149 ;
		CCP1CONbits.DC1B0 = 1 ;
		CCP1CONbits.DC1B1 = 1 ;
		msdelay(3000) ;
		
		// 60% Duty Cycle
		CCPR1L = 112 ;
		CCP1CONbits.DC1B0 = 1 ;
		CCP1CONbits.DC1B1 = 0 ;
		msdelay(3000) ;
		
		// 40% Duty Cycle
		CCPR1L = 74 ;
		CCP1CONbits.DC1B0 = 1 ;
		CCP1CONbits.DC1B1 = 1 ;
		msdelay(3000) ;
		
		// 20% Duty Cycle
		CCPR1L = 37 ;
		CCP1CONbits.DC1B0 = 0 ;
		CCP1CONbits.DC1B1 = 1 ;
		msdelay(3000) ;
	}
}