#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
    //PIE0bits.INT0IE=1; //enable interrupt source INT0 
    PIE0bits.TMR0IE=1;
    PIE2bits.C1IE=1;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
/*
void __interrupt(high_priority) HighISR()
{
    if (PIR2bits.C1IF) {
        LATHbits.LATH3=!LATHbits.LATH3;
        PIR2bits.C1IF=0;
        //clear flag here
    }
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
}
 */
void __interrupt(high_priority) HighISR2()
{
    if (PIR0bits.TMR0IF) {
        LATDbits.LATD7 = !LATDbits.LATD7;
        PIR0bits.TMR0IF=0;
        TMR0H = 0x1600;
        TMR0L = 129;
        
    }
    
}

