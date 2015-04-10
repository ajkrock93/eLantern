/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       light_state.c
* Date Created :   Thursday March 26, 2015 08:51:28 PM
* Last Edited :    Thursday April 09, 2015 08:51:30 PM
* Description :    This function handles the state of the
                   light
----------------------------------------------------------*/

 #define F_CPU 1000000

#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>

#include "light_state.h"
#include "button_state.h"
#include "timer.h"
#include "io.h"

//Inits state of light
unsigned int light_state = OFF;

void light_status(){
	switch(light_state){
		case OFF:
			OCR0B = 0;		//Turns light off/make MACRO
			if(button_flag == 1){
				light_state = ON;
			}
			if(get_sleep() > SLEEP_TIME){
				set_sleep_mode(SLEEP_MODE_PWR_DOWN);
				sleep_mode();
			}
			break;
		case ON:
			OCR0B = 120;		//Turns light on/make MACRO
			if(button_flag == 1){
				light_state = OFF;
				sleep_timer = 0;
			}
			break;
		default:
			break;
	}
}

