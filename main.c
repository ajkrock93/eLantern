/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       main.c
* Date Created :   Monday March 23, 2015 07:53:28 PM
* Last Edited :    Friday March 27, 2015 12:53:54 AM
* Description :
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

unsigned int eLanternServicePeriod = 10;

int main(void){
	DDRB |= (1 << PORTB0);	//Configured as output for testing 
	PORTB |= (1 << PORTB2);
	timer_init();
	interrupt_init();
	while(1){
		if(get_ticks() > eLanternServicePeriod){	//Does these jobs every period defined
			eLanternServicePeriod += 10;
			button_flag_status();
			button_status();
			light_status();
		}
	}
	return 0;	
}

//Think about just using ticks and reseting it to 0
