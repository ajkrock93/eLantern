/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.h
* Date Created :   Monday March 23, 2015 07:59:34 PM
* Last Edited :    Friday March 27, 2015 01:42:50 AM
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
extern unsigned int timer_a;
extern unsigned int timer_b;
#endif //TIMER_H
