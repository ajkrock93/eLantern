/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.c
* Date Created :   Monday March 23, 2015 07:59:26 PM
* Last Edited :    Thursday March 26, 2015 08:08:42 PM
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

//Initializes timer to CTC for 1 ms period
void timer_init(){	
	cli();
	TCCR0A = (WGM01x);
	TCCR0B = (CS01x);
	TIMSK = (OCIE0Ax);
	OCR0A = 125;
	sei();
}

//Function returns current tick value
unsigned int get_ticks(){
	return ticks;
}

unsigned int get_debounce(){
	return debounce_timer;
}

//Interrupts every 1 ms and adds a tick 
ISR(TIMER0_COMPA_vect){	
	ticks ++;
	debounce_timer ++;
	//PORTB |= (1 << PORTB1);
	//_delay_us(5);
	//PORTB &= ~(1 <<PORTB1);
}
