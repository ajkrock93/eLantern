/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.c
* Date Created :   Monday March 23, 2015 07:59:26 PM
* Last Edited :    Monday May 04, 2015 04:56:09 PM
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
	//Start moving over to timer1
	TCCR1 = (CTC1x)|(PWM1Ax)|(COM1A1x)|(CS11x)|(CS10x);
	OCR1C = 250;
	TIMSK = (TOIE1x); //Overflow int
	OCR1A = 0;
	//To do PWM set OCR1A to a value
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
ISR(TIMER1_OVF_vect){	
	ticks ++;
	debounce_timer ++;
	sleep_timer ++;
	select_timer ++;
	runtime_timer ++;
	fade_timer ++;
}
