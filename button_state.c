/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.c
* Date Created :   Thursday March 26, 2015 01:21:11 PM
* Last Edited :    Tuesday April 07, 2015 03:39:47 PM
* Description :    This file handles the button state
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "button_state.h"
#include "io.h"
#include "timer.h"

//TODO
//Change switch_state to button_state
unsigned int button_flag = 0;
unsigned int switch_state = 0;

//Initializes the interrupt vector to interrupt on low-input
//with INT0
void interrupt_init(){
	cli();
	GIMSK = (PCIEx);
	PCMSK = (PCINT3x);
	sei();
}

//TODO
//Maybe change the name of this function

//Check to see if button flag is set
void button_flag_status(){
	if((button_flag == 1) && (switch_state == NOT_PRESSED)){
		debounce_timer = 0;
		switch_state = PRESSED;
	}else{
		// do nothing
	}
}

//Debounce switch statement
void button_status(){
	switch(switch_state){
		case NOT_PRESSED:
			break;
		case PRESSED:
		if(get_debounce() < DEBOUNCE_TIME){
				switch_state = PRESSED;	
			}
			if(get_debounce() > DEBOUNCE_TIME){
				switch_state = NOT_PRESSED;
				button_flag = 0;
			}
			break;
		default:
			break;
	}
}

ISR(PCINT0_vect){
	button_flag = 1;
}
