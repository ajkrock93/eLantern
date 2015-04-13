/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.h
* Date Created :   Monday March 23, 2015 07:59:34 PM
* Last Edited :    Saturday April 11, 2015 03:03:48 PM
* Description :
----------------------------------------------------------*/

#ifndef TIMER_H
#define TIMER_H

void timer_init();
unsigned int get_ticks();
unsigned int get_debounce();
unsigned int get_sleep();

extern unsigned int ticks;
extern unsigned int debounce_timer;
extern unsigned int sleep_timer;
extern unsigned int select_timer;
extern unsigned int runtime_timer;
#endif //TIMER_H
