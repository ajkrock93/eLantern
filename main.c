/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       main.c
* Date Created :   Monday March 23, 2015 07:53:28 PM
* Last Edited :    Wednesday March 25, 2015 12:40:33 AM
* Description :
----------------------------------------------------------*/

#define F_CPU 1000000

#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//#include <avr/sfr_defs.h>

#include "timer.h"
#include "io.h"

int main(void){
	DDRB |= (1 << PORTB0);	//Configured as output for testing 
	timer_init();
	while(1){
		if(get_ticks() < 10){		//rename 10
			//do jobs
				//button status
		}	
	}
	return 1;
}

