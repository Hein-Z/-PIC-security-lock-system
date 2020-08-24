/* 
 * File:   KEYPAD.h
 * Author: acer
 *
 * Created on December 23, 2019, 11:20 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#ifdef	__cplusplus
extern "C" {
#endif
#define KEYPAD_PORT   PORTC
#define KEYPAD_TRIS    TRISC
#define OUT_KEYPAD_PORT PORTB
#define OUT_KEYPAD_TRIS  TRISB
#define ENTER               1
#define DELETE           (1<<1)
#define _X0                  (1<<4)
#define _X1                  (1<<5)
#define _X2                  (1<<6)
#define _X3                  (1<<7)
#define _Y0                  (1<<3)
#define _Y1                  (1<<2)
#define _Y2                  (1<<1)
#define _Y3                  (1<<0)
#define  O_X0                 (1<<0)
#define  O_X1                 (1<<0)
#define  O_X2                 (1<<0)
#define  O_X3                 (1<<0)
    
    void Keypad_Init(void);
    char Keypad_Scanner(void);
    char  Switch_Press_Scan(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* KEYPAD_H */

