/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       main.c
* Date Created :   Monday March 23, 2015 07:53:28 PM
* Last Edited :    Thursday May 14, 2015 11:12:14 PM
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
#include "softuart.h"

unsigned int eLanternServicePeriod = SERVICE_PERIOD;
//unsigned int testPeriod = 1000;

//Description:
//This main loop runs every time get_ticks returns a value 
//longer than eLanternServicePeriod

int main(void){
	timer_init();
	interrupt_init();
	button_init();
	light_init();
	softuart_init();
	while(1){
		if(get_ticks() > eLanternServicePeriod){	//Does these jobs every period defined
			eLanternServicePeriod += 10;	//Update the service period
			button_status();
			light_status();
			print_light_state();
		}
/*		if(get_ticks() > testPeriod){
			testPeriod += 1000;
			softuart_putchar('1');
		}*/
	}
	return 0;	
}

