/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       light_state.c
* Date Created :   Thursday March 26, 2015 08:51:28 PM
* Last Edited :    Monday April 13, 2015 09:52:32 AM
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
				light_state = ON_STATE;
				select_timer = 0;
			}
			//if(get_sleep() > SLEEP_TIME){
			//	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
			//	sleep_mode();
			//}
			break;
		case ON_STATE:
			if(select_timer > 1000){
				light_state = LOW;
				//runtime_timer = 0;
			}
			break;
		case LOW:
			OCR0B = 25;
			if(button_flag == 1){
				light_state = WAITING_STATE_1;
				select_timer = 0;
			}
			//if(runtime_timer > 10000){
			//	light_state = OFF;
			//}
			break;
		case WAITING_STATE_1:
			if(button_flag == 1 && select_timer < 1000){
				light_state = OFF;
			}
			else{
				light_state = MEDIUM;
			}
			break;
		case MEDIUM:
			OCR0B = 75;
            if(button_flag == 1){
                light_state = WAITING_STATE_2;
                select_timer = 0;
            }
            if(runtime_timer > 10000){
                light_state = OFF;
            }
            break;

		default:
			break;
	}
}







