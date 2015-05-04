/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.h
* Date Created :   Thursday March 26, 2015 01:34:01 PM
* Last Edited :    Saturday April 18, 2015 06:17:11 PM
* Description :
----------------------------------------------------------*/

#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H

void button_init();
void interrupt_init();
void button_status();

extern unsigned int button_flag;
#endif //BUTTON_STATE_H
