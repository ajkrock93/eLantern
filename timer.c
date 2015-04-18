/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.c
* Date Created :   Monday March 23, 2015 07:59:26 PM
* Last Edited :    Saturday April 18, 2015 05:09:50 PM
* Description :    This file handles timer setup, 
				   counting and returning timer values
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "timer.h"
#include "io.h"

//Starting timers at 0
unsigned int ticks = 0;
unsigned int debounce_timer = 0;
unsigned int sleep_timer = 0;
unsigned int select_timer = 0;
unsigned int runtime_timer = 0;
unsigned int fade_timer = 0;

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
	unsigned int temp;
	cli();
	temp = ticks;
	sei();
	return temp;
}

//Function returns current debounce timer value
unsigned int get_debounce(){
	unsigned int temp;
	cli();
	temp = debounce_timer;
	sei();
	return temp;
}

//Function that returns sleep timer value
unsigned int get_sleep(){
	unsigned int temp;
	cli();
	temp = sleep_timer;
	sei();
	return temp;
}

//Function that returns select timer value
unsigned int get_select(){
	unsigned int temp;
	cli();
	temp = select_timer;
	sei();
	return temp;
}

//Function that returns runtime timer value
unsigned int get_runtime(){
	unsigned int temp;
	cli();
	temp = runtime_timer;
	sei();
	return temp;
}

//Function that returns the fade timer value
unsigned int get_fade(){
	unsigned int temp;
	cli();
	temp = fade_timer;
	sei();
	return temp;
}

//Interrupts every 1 ms and adds a tick 
ISR(TIMER0_COMPA_vect){	
	ticks ++;
	debounce_timer ++;
	sleep_timer ++;
	select_timer ++;
	runtime_timer ++;
	fade_timer ++;

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
