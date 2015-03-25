/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.c
* Date Created :   Monday March 23, 2015 07:59:26 PM
* Last Edited :    Wednesday March 25, 2015 12:29:05 AM
* Description :
----------------------------------------------------------*/

//#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

#include "timer.h"
#include "io.h"

unsigned ticks = 0;

void timer_init(){
	cli();
	TCCR0A = (WGM01x)|(COM0A0x);
	TCCR0B = (CS01x);
	TIMSK = (OCIE0Ax);
	OCR0A = 125;
	//unsigned ticks = 0;
	sei();
}

unsigned int get_ticks(){
	return ticks;
}

ISR(TIMER0_COMPA_vect){
	//static unsigned int ticks = 0;
	ticks ++;
}
