#include<p18f4550.h>

void delay(unsigned int t);
void timer_isr(void);

extern void _startup (void);
#pragma code RESET_INTERRUPT_VECTOR = 0x1000

void reset (void)
{
        _asm goto _startup _endasm
}

#pragma code
#pragma code HIGH_INTERRUPT_VECTOR = 0x1008
void high_ISR (void)
{
       _asm goto timer_isr _endasm
}

#pragma code

void timer_isr(void){
PORTDbits.RD0 =~ PORTDbits.RD0;
INTCONbits.TMR0IF = 0;
TMR0H = 0x6D;
TMR0L = 0x75;
}

void delay(unsigned int t){
unsigned int i,j;
for(i = 0;i<t;i++)
for(j=0;j<1275;j++);
}

void main(){
TRISDbits.RD0 = 0;
PORTDbits.RD0 = 0;
T0CON = 0x03;
TMR0H = 0x6D;
TMR0L = 0x75;

INTCONbits.GIE = 1;
INTCONbits.TMR0IE = 1;
T0CONbits.TMR0ON = 1;
while(1);
}