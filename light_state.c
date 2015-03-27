/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       light_state.c
* Date Created :   Thursday March 26, 2015 08:51:28 PM
* Last Edited :    Friday March 27, 2015 12:56:46 AM
* Description :
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

unsigned int light_state = 0;

void light_status(){
	switch(light_state){
		case OFF:
			PORTB &= ~(1 << PORTB0);
			if(button_flag == 1){
				light_state = ON;
			}
			if(get_sleep() > 3000){
				set_sleep_mode(SLEEP_MODE_PWR_DOWN);
				sleep_mode();
			}
			break;
		case ON:
			PORTB |= (1 << PORTB0);
			if(button_flag == 1){
				light_state = OFF;
				sleep_timer = 0;
			}
			break;
		default:
			break;
	}
}
