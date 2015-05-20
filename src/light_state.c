/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       light_state.c
* Date Created :   Thursday March 26, 2015 08:51:28 PM
* Last Edited :    Wednesday May 20, 2015 11:30:12 AM
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
#include "softuart.h"

unsigned int temp = 100;
char char_light_state;

//Inits light state
unsigned int light_state = OFF;

//Inits fade direction
unsigned int direction = UP;

//Inits state of light pin
void light_init(){
	DDRB |= LIGHT_PIN;
}

void print_light_state(){
	if(light_state != temp){
		char_light_state = (char)light_state;
		softuart_putchar(char_light_state);
		//softuart_putchar('0');
		//temp = light_state;
	}
	temp = light_state;
}

//Finite state machine that controls what the 
//light is doing
void light_status(){
	switch(light_state){
		case OFF:
			OCR1A = OFF;
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
			if(button_flag == 1 && get_select() < SELECT_TIME){
				OCR1A = OFF;
				fade_timer = 0;
				runtime_timer = 0;
				light_state = FADE;
			}
			else if(get_select() > SELECT_TIME){
				light_state = LOW;
				runtime_timer = 0;
			}
			break;
		case LOW:
			OCR1A = LIGHT_LOW;
			if(button_flag == 1){
				light_state = WAITING_STATE_1;
				select_timer = 0;
			}
			if(get_runtime() > RUNTIME){
				light_state = OFF;
			}
			break;
		case WAITING_STATE_1:
			if(button_flag == 1 && get_select() < SELECT_TIME){
				light_state = OFF;
			}
			else if(get_select() > SELECT_TIME){
				runtime_timer = 0;
				light_state = MEDIUM;
			}
			break;
		case MEDIUM:
			OCR1A = LIGHT_MEDIUM;
            if(button_flag == 1){
                light_state = WAITING_STATE_2;
                select_timer = 0;
            }
            if(get_runtime() > RUNTIME){
                light_state = OFF;
            }
            break;
		case WAITING_STATE_2:
			if(button_flag == 1 && get_select() < SELECT_TIME){
                light_state = OFF;
            }
            else if(get_select() > SELECT_TIME){
				runtime_timer = 0;
                light_state = HIGH;
            }
			break;
		case HIGH:
			OCR1A = LIGHT_HIGH;
            if(button_flag == 1){
                light_state = WAITING_STATE_3;
                select_timer = 0;
            }
			if(get_runtime() > RUNTIME){
				light_state = OFF;
			}
			break;
		case WAITING_STATE_3:
			if(button_flag == 1 && get_select() < SELECT_TIME){
				light_state = OFF;
            }   
            else if(get_select() > SELECT_TIME){
				runtime_timer = 0;
                light_state = LOW;
            }   
			break;
		case FADE:
			if(get_fade() > 50){
				if(direction == UP && OCR0B < 121){
					OCR1A++;
					if(OCR1A == 120){
						direction = DOWN;
					}
				}
				if(direction == DOWN && OCR0B > 0){
					OCR1A--;
					if(OCR1A == 1){
					direction = UP;
					}
				}
				fade_timer = 0;
			}
			if(button_flag == 1 || get_runtime() > RUNTIME){
				light_state = OFF;
			}
			break;
		default:
			break;
	}
}
