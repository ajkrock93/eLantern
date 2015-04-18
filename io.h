/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       io.h
* Date Created :   Monday March 23, 2015 08:01:43 PM
* Last Edited :    Saturday April 18, 2015 05:08:01 PM
* Description :    This file handles all the macros of the 
				   project
----------------------------------------------------------*/

#ifndef IO_H
#define IO_H

//Variables
#define SERVICE_PERIOD	10

//Button state Macros
#define WAITING         0
#define PRESSED			1
#define DEBOUNCING		2
#define DEBOUNCE_TIME	100 //in milliseconds

//Light State Macros
#define LIGHT_LOW		25
#define LIGHT_MEDIUM	75
#define LIGHT_HIGH		120
#define OFF				0
#define ON_STATE		1
#define LOW				2
#define	WAITING_STATE_1	3
#define	MEDIUM			4
#define WAITING_STATE_2	5
#define HIGH			6
#define WAITING_STATE_3	7
#define FADE			8
#define UP				1
#define DOWN			0
#define SLEEP_TIME		10000 //in milliseconds
#define SELECT_TIME		300
#define RUNTIME			5000

//Timer/Counter1 control register A
#define COM0A1x			(1<<COM0A1)
#define COM0A0x    	 	(1<<COM0A0)
#define COM0B1x    	 	(1<<COM0B1)
#define COM0B0x    	 	(1<<COM0B0)
#define WGM01x     	 	(1<<WGM01)
#define WGM00x     	 	(1<<WGM00)

//Timer/Counter1 control register B
#define FOC0Ax			(1<<FOC0A)
#define FOC0Bx      	(1<<FOC0B)
#define WGM02x      	(1<<WGM02)
#define CS02x       	(1<<CS02)
#define CS01x       	(1<<CS01)
#define CS00x       	(1<<CS00)

//Timer/Counter Interrupt Mask Register
#define	OCIE0Ax			(1<<OCIE0A)
#define OCIE0Bx			(1<<OCIE0B)

//MCU Control Register
#define ISC00x			(1<<ISC00)
#define ISC01x			(1<<ISC01)

//GIMSK Genral Interrupt Mask Register
#define INT0x			(1<<INT0)
#define PCIEx			(1<<PCIE)

//PCMSK - Pin Change Mask Register/for interrupts
#define PCINT3x			(1<<PCINT3)

//MCUCR MCU Control Register
#define SM1x			(1<<SM1)
#define SEx				(1<<SE)


#endif //IO_H
