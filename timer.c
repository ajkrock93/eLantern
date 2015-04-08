/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.c
* Date Created :   Monday March 23, 2015 07:59:26 PM
* Last Edited :    Tuesday April 07, 2015 10:57:47 PM
* Description :    This file handles timer setup
----------------------------------------------------------*/

#define F_CPU 1000000

//#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "timer.h"
#include "io.h"

//Starting timers at 0
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
	OCR0B = 0;
	sei();
}

//Function returns current tick value
unsigned int get_ticks(){
	return ticks;
}

//Function returns current debounce timer value
unsigned int get_debounce(){
	return debounce_timer;
}

//Function that returns sleep timer value
unsigned int get_sleep(){
	return sleep_timer;
}

//Interrupts every 1 ms and adds a tick 
ISR(TIMER0_COMPA_vect){	
	ticks ++;
	debounce_timer ++;
	sleep_timer ++;

	//Turn light on or keep it off
	if(OCR0B == 0){
		PORTB &= ~(1 << PORTB0);
	}
	else{
		PORTB |= (1 << PORTB0);
	}

}

ISR(TIMER0_COMPB_vect){
	//Turn light off
	PORTB &= ~(1 << PORTB0);
}
