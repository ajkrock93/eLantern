/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.c
* Date Created :   Thursday March 26, 2015 01:21:11 PM
* Last Edited :    Monday April 13, 2015 08:18:47 PM
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
unsigned int button_state = WAITING;

//Initializes the interrupt vector
void interrupt_init(){
	cli();
	GIMSK = (PCIEx);
	PCMSK = (PCINT3x);
	sei();
}


//Debounce switch statement
void button_status(){
	switch(button_state){
		case WAITING:
			if(button_flag == 1){
				debounce_timer = 0;
				button_state = PRESSED;
			}
			break;
		case PRESSED:
			button_flag = 0;
			button_state = DEBOUNCING;
			break;
		case DEBOUNCING:
			if(debounce_timer > DEBOUNCE_TIME){
				button_state = WAITING;
			}
			break;
		default:
			break;
	}
}

ISR(PCINT0_vect){
	if(button_state == DEBOUNCING){
		button_flag = 0;
	}
	else{
		button_flag = 1;
	}
}
