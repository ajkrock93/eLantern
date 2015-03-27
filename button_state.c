/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.c
* Date Created :   Thursday March 26, 2015 01:21:11 PM
* Last Edited :    Thursday March 26, 2015 08:40:44 PM
* Description :
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "button_state.h"
#include "io.h"
#include "timer.h"

unsigned int button_flag = 0;
unsigned int switch_state = 0;

void interrupt_init(){
	cli();
	MCUCR = (ISC01x)|(ISC00x);
	GIMSK = (INT0x);
	sei();
}

//Check to see if button flag is set
void button_flag_status(){
	if((button_flag == 1) && (switch_state == NOT_PRESSED)){
		debounce_timer = 0;
		switch_state = PRESSED;
		PORTB |= (1 << PORTB0);
	}else{
		// do nothing
	}
}

//Debounce switch statement
void button_status(){
	switch(switch_state){
		case NOT_PRESSED:
			PORTB &= ~(1 << PORTB0);
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
	}
}


ISR(INT0_vect){
	button_flag = 1;
}

