/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.c
* Date Created :   Thursday March 26, 2015 01:21:11 PM
* Last Edited :    Monday March 30, 2015 04:52:15 PM
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
	//MCUCR = (ISC01x)|(ISC00x);
	GIMSK = (INT0x);
	sei();
}

//TODO
//Maybe change the name of this function

//Check to see if button flag is set
void button_flag_status(){
	if((button_flag == 1) && (switch_state == NOT_PRESSED)){
		debounce_timer = 0;
		switch_state = PRESSED;
		//PORTB |= (1 << PORTB0);
	}else{
		// do nothing
	}
}

//Debounce switch statement
void button_status(){
	switch(switch_state){
		case NOT_PRESSED:
			//PORTB &= ~(1 << PORTB0);
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

ISR(INT0_vect){
	button_flag = 1;
}

