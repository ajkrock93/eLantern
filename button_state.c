/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.c
* Date Created :   Thursday March 26, 2015 01:21:11 PM
* Last Edited :    Thursday April 09, 2015 08:51:33 PM
* Description :    This file handles the button state
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "button_state.h"
#include "io.h"
#include "timer.h"

unsigned int button_flag = 0;
unsigned int button_state = NOT_PRESSED;

//Initializes the interrupt vector
void interrupt_init(){
	cli();
	GIMSK = (PCIEx);
	PCMSK = (PCINT3x);
	sei();
}

//Check to see if button flag is set
void button_flag_status(){
	if((button_flag == 1) && (button_state == NOT_PRESSED)){
		debounce_timer = 0;
		button_state = PRESSED;
	}else{
		// do nothing
	}
}

//Debounce switch statement
void button_status(){
	switch(button_state){
		case NOT_PRESSED:
			break;
		case PRESSED:
			if(get_debounce() < DEBOUNCE_TIME){
				button_state = PRESSED;	
			}
			if(get_debounce() > DEBOUNCE_TIME){
				button_state = NOT_PRESSED;
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
