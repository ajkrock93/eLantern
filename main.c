/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       main.c
* Date Created :   Monday March 23, 2015 07:53:28 PM
* Last Edited :    Monday May 04, 2015 04:56:12 PM
* Description :    This file handles the main job loop
				   that runs every eLanternServicePeriod	
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>

#include "timer.h"
#include "button_state.h"
#include "light_state.h"
#include "io.h"

unsigned int eLanternServicePeriod = SERVICE_PERIOD;

//Description:
//This main loop runs every time get_ticks returns a value 
//longer than eLanternServicePeriod
int main(void){
	timer_init();
	interrupt_init();
	button_init();
	light_init();
	while(1){
		if(get_ticks() > eLanternServicePeriod){	//Does these jobs every period defined
			eLanternServicePeriod += 10;	//Update the service period
			button_status();
			light_status();
		}
	}
	return 0;	
}

