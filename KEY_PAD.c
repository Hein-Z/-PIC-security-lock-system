#include <xc.h>
#include "KEYPAD.h"
#define _XTAL_FREQ  4000000UL

void Keypad_Init(void){
    KEYPAD_TRIS=0xF0;
    KEYPAD_PORT= 0;
    OUT_KEYPAD_TRIS=0xFF;
    OUT_KEYPAD_PORT=0x00;
     ANSELH =0;
}
char Keypad_Scanner(void){
     __delay_ms(10);
    KEYPAD_PORT&=0xF0;
    KEYPAD_PORT|=_Y0;
    if(KEYPAD_PORT&_X0){__delay_ms(50);
    while(KEYPAD_PORT==_X0)
    ;
    __delay_ms(50);
    return ENTER;}
    
    if(KEYPAD_PORT&_X1){__delay_ms(50);
    while(KEYPAD_PORT==_X1)
        ;
    __delay_ms(50);
    return '0';}
    
    if(KEYPAD_PORT&_X2){__delay_ms(50);
    while(KEYPAD_PORT==_X2)
        ;
    __delay_ms(50);
    return DELETE;}
    
    if(KEYPAD_PORT&_X3){__delay_ms(50);
    while(KEYPAD_PORT==_X3)
        ;
    __delay_ms(50);
    return 'H';}
    
    __delay_ms(10);
   ///////////////////////////////////// 
    KEYPAD_PORT&=0xF0;
    KEYPAD_PORT|=_Y1;
    if(KEYPAD_PORT&_X0){__delay_ms(50);
    while(KEYPAD_PORT==_X0)
        ;
    __delay_ms(50);
    return '1';}
    
    if(KEYPAD_PORT&_X1){__delay_ms(50);
    while(KEYPAD_PORT==_X1)
        ;
    __delay_ms(50);
    return '2';}
    
    if(KEYPAD_PORT&_X2){__delay_ms(50);
    while(KEYPAD_PORT==_X2)
        ;
    __delay_ms(50);
    return '3';}
    
    if(KEYPAD_PORT&_X3){__delay_ms(50);
    while(KEYPAD_PORT==_X3)
        ;
    __delay_ms(50);
    return 'P';}
    __delay_ms(10);
    ///////////////////////////////////
    KEYPAD_PORT&=0xF0;
    KEYPAD_PORT|=_Y2;
    if(KEYPAD_PORT&_X0){__delay_ms(50);
    while(KEYPAD_PORT==_X0)
        ;
    __delay_ms(50);
    return '4';}
    
    if(KEYPAD_PORT&_X1){__delay_ms(50);
    while(KEYPAD_PORT==_X1)
        ;
    __delay_ms(50);
    return '5';}
    
    if(KEYPAD_PORT&_X2){__delay_ms(50);
    while(KEYPAD_PORT==_X2)
        ;
    __delay_ms(50);
    return '6';}
    
    if(KEYPAD_PORT&_X3){__delay_ms(50);
    while(KEYPAD_PORT==_X3)
        ;
    __delay_ms(50);
    return 'G';}
    __delay_ms(10);
    ///////////////////////////////////////
    KEYPAD_PORT&=0xF0;
    KEYPAD_PORT|= _Y3;
    if(KEYPAD_PORT&_X0){__delay_ms(50);
    while(KEYPAD_PORT==_X0)
        ;
    __delay_ms(50);
    return '7';}
    
    if(KEYPAD_PORT&_X1){__delay_ms(50);
    while(KEYPAD_PORT==_X1)
        ;
    __delay_ms(50);
    return '8';}
    
    if(KEYPAD_PORT&_X2){__delay_ms(50);
    while(KEYPAD_PORT==_X2)
        ;
    __delay_ms(50);
    return '9';}
    
    if(KEYPAD_PORT&_X3){__delay_ms(50);
    while(KEYPAD_PORT==_X3)
        ;
    __delay_ms(50);
    return 'Y';}

  return '_';
    }
//char OUT_Keypad_Scanner(void){
//     __delay_ms(10);
//    KEYPAD_PORT&=0xF0;
//    KEYPAD_PORT|=_Y0;
//    if(OUT_KEYPAD_PORT&O_X0){__delay_ms(50);
//    while(OUT_KEYPAD_PORT==O_X0)
//    ;
//    __delay_ms(50);
//    return ENTER;}
//    
//    if(KEYPAD_PORT&O_X1){__delay_ms(50);
//    while(KEYPAD_PORT==O_X1)
//        ;
//    __delay_ms(50);
//    return '0';}
//    
//    if(KEYPAD_PORT&O_X2){__delay_ms(50);
//    while(KEYPAD_PORT==O_X2)
//        ;
//    __delay_ms(50);
//    return DELETE;}
//    
//    if(KEYPAD_PORT&O_X3){__delay_ms(50);
//    while(KEYPAD_PORT==O_X3)
//        ;
//    __delay_ms(50);
//    return 'H';}
//    
//    __delay_ms(10);
//   ///////////////////////////////////// 
//    KEYPAD_PORT&=0xF0;
//    KEYPAD_PORT|=_Y1;
//    if(KEYPAD_PORT&O_X0){__delay_ms(50);
//    while(KEYPAD_PORT==O_X0)
//        ;
//    __delay_ms(50);
//    return '1';}
//    
//    if(KEYPAD_PORT&O_X1){__delay_ms(50);
//    while(KEYPAD_PORT==O_X1)
//        ;
//    __delay_ms(50);
//    return '2';}
//    
//    if(KEYPAD_PORT&O_X2){__delay_ms(50);
//    while(KEYPAD_PORT==O_X2)
//        ;
//    __delay_ms(50);
//    return '3';}
//    
//    if(KEYPAD_PORT&O_X3){__delay_ms(50);
//    while(KEYPAD_PORT==O_X3)
//        ;
//    __delay_ms(50);
//    return 'P';}
//    __delay_ms(10);
//    ///////////////////////////////////
//    KEYPAD_PORT&=0xF0;
//    KEYPAD_PORT|=_Y2;
//    if(KEYPAD_PORT&O_X0){__delay_ms(50);
//    while(KEYPAD_PORT==O_X0)
//        ;
//    __delay_ms(50);
//    return '4';}
//    
//    if(KEYPAD_PORT&O_X1){__delay_ms(50);
//    while(KEYPAD_PORT==O_X1)
//        ;
//    __delay_ms(50);
//    return '5';}
//    
//    if(KEYPAD_PORT&O_X2){__delay_ms(50);
//    while(KEYPAD_PORT==O_X2)
//        ;
//    __delay_ms(50);
//    return '6';}
//    
//    if(KEYPAD_PORT&O_X3){__delay_ms(50);
//    while(KEYPAD_PORT==O_X3)
//        ;
//    __delay_ms(50);
//    return 'G';}
//    __delay_ms(10);
//    ///////////////////////////////////////
//    KEYPAD_PORT&=0xF0;
//    KEYPAD_PORT|= _Y3;
//    if(KEYPAD_PORT&O_X0){__delay_ms(50);
//    while(KEYPAD_PORT==O_X0)
//        ;
//    __delay_ms(50);
//    return '7';}
//    
//    if(KEYPAD_PORT&O_X1){__delay_ms(50);
//    while(KEYPAD_PORT==O_X1)
//        ;
//    __delay_ms(50);
//    return '8';}
//    
//    if(KEYPAD_PORT&O_X2){__delay_ms(50);
//    while(KEYPAD_PORT==O_X2)
//        ;
//    __delay_ms(50);
//    return '9';}
//    
//    if(KEYPAD_PORT&O_X3){__delay_ms(50);
//    while(KEYPAD_PORT==O_X3)
//        ;
//    __delay_ms(50);
//    return 'Y';}
//
//  return '_';
//    }

char  Switch_Press_Scan(void){
    char key='_';
    while(key=='_')
        key=Keypad_Scanner();
    return key;
}
