/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.h
* Date Created :   Monday March 23, 2015 07:59:34 PM
* Last Edited :    Saturday May 09, 2015 01:15:44 PM
* Description :
----------------------------------------------------------*/

#ifndef TIMER_H
#define TIMER_H

void timer_init();
unsigned int get_ticks();
unsigned int get_debounce();
unsigned int get_sleep();
unsigned int get_select();
unsigned int get_runtime();
unsigned int get_fade();

extern unsigned int ticks;
extern unsigned int debounce_timer;
extern unsigned int sleep_timer;
extern unsigned int select_timer;
extern unsigned int runtime_timer;
extern unsigned int fade_timer;

#endif //TIMER_H
