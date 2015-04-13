/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       main.c
* Date Created :   Monday March 23, 2015 07:53:28 PM
* Last Edited :    Monday April 13, 2015 09:52:40 AM
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

/*
//Description:
//This function sets up the project
void Project_Init(){
	//unsigned int eLanternServicePeriod = SERVICE_PERIOD;
	//DDRB |= MACRO;
	//PORTB |= MACRO;
	//timer_imit();
	//interrupt_init();
}
*/

unsigned int eLanternServicePeriod = SERVICE_PERIOD;

//Description:
//This main loop runs every time get_ticks returns a value 
//longer than eLanternServicePeriod
int main(void){
	DDRB |= (1 << PORTB0);		//Configured as output for testing 
	PORTB |= (1 << PORTB3);		//Set button input for high impedence	
	timer_init();
	interrupt_init();
	while(1){
		if(get_ticks() > eLanternServicePeriod){	//Does these jobs every period defined
			eLanternServicePeriod += 10;	//Update the service period
			button_status();
			light_status();
			//button_status();
		}
	}
	return 0;	
}

//Think about just using ticks and reseting it to 0
