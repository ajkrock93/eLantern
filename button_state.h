/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       button_state.h
* Date Created :   Thursday March 26, 2015 01:34:01 PM
* Last Edited :    Friday March 27, 2015 01:40:38 AM
* Description :
----------------------------------------------------------*/

#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H

void interrupt_init();
void button_status();
void button_flag_status();

extern unsigned int button_flag;
#endif //BUTTON_STATE_H
