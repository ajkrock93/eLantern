/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.c
* Date Created :   Monday March 23, 2015 07:59:26 PM
* Last Edited :    Friday March 27, 2015 12:50:13 AM
* Description :
----------------------------------------------------------*/

#define F_CPU 1000000

//#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "timer.h"
#include "io.h"

unsigned int ticks = 0;
unsigned int debounce_timer = 0;
unsigned int sleep_timer = 0;

unsigned int timer_a;
unsigned int timer_b;

//Initializes timer to CTC for 1 ms period
void timer_init(){	
	cli();
	TCCR0A = (WGM01x);
	TCCR0B = (CS01x);
	TIMSK = (OCIE0Ax)|(OCIE0Bx);
	OCR0A = 125;
	OCR0B = 20;
	sei();
}

//Function returns current tick value
unsigned int get_ticks(){
	return ticks;
}

unsigned int get_debounce(){
	return debounce_timer;
}

unsigned int get_sleep(){
	return sleep_timer;
}
//Interrupts every 1 ms and adds a tick 
ISR(TIMER0_COMPA_vect){	
	ticks ++;
	debounce_timer ++;
	sleep_timer ++;
}

ISR(TIMER0_COMPB_vect){
	//nothing here yet
}
