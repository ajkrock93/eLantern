/*--------------------------------------------------------
* Author :         Andrew Krock
* Filename :       io.h
* Date Created :   Monday March 23, 2015 08:01:43 PM
* Last Edited :    Wednesday March 25, 2015 12:21:12 AM
* Description :
----------------------------------------------------------*/

#ifndef IO_H
#define IO_H

//Timer/Counter1 control register A
#define COM0A1x     (1<<COM0A1)
#define COM0A0x     (1<<COM0A0)
#define COM0B1x     (1<<COM0B1)
#define COM0B0x     (1<<COM0B0)
#define WGM01x      (1<<WGM01)
#define WGM00x      (1<<WGM00)

//Timer/Counter1 control register B
#define FOC0Ax      (1<<FOC0A)
#define FOC0Bx      (1<<FOC0B)
#define WGM02x      (1<<WGM02)
#define CS02x       (1<<CS02)
#define CS01x       (1<<CS01)
#define CS00x       (1<<CS00)

//Timer/Counter Interrupt Mask Register
#define	OCIE0Ax		(1<<OCIE0A)
#endif //IO_H
