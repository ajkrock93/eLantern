/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       timer.h
* Date Created :   Monday March 23, 2015 07:59:34 PM
* Last Edited :    Thursday March 26, 2015 08:40:39 PM
* Description :
----------------------------------------------------------*/

#ifndef TIMER_H
#define TIMER_H

void timer_init();
unsigned int get_ticks();
unsigned int get_debounce();

extern unsigned int ticks;
extern unsigned int debounce_timer;
#endif //TIMER_H
