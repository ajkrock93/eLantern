/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       main.c
* Date Created :   Monday March 23, 2015 07:53:28 PM
* Last Edited :    Monday March 30, 2015 04:55:35 PM
* Description :    This file handles main job loop that
				   runs how long the eLanternServicePeriod
				   is set	
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
//#include <avr/interrupt.h>
//#include <avr/sfr_defs.h>

#include "timer.h"
#include "button_state.h"
#include "light_state.h"
#include "io.h"

//TODO
//Make this variable a macro
unsigned int eLanternServicePeriod = 10;

//Description:
//This main loop runs every time get_ticks returns a value 
//longer than eLanternServicePeriod
int main(void){
	DDRB |= (1 << PORTB0);	//Configured as output for testing 
	PORTB |= (1 << PORTB2);
	timer_init();
	interrupt_init();
	while(1){
		if(get_ticks() > eLanternServicePeriod){	//Does these jobs every period defined
			eLanternServicePeriod += 10;	//Update the service period
			button_flag_status();
			button_status();
			light_status();
		}
	}
	return 0;	
}

//Think about just using ticks and reseting it to 0
