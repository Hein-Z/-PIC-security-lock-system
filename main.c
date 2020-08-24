// PIC16F887 Configuration Bit Settings
// 'C' source line config statements
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdio.h>
#include"KEYPAD.h"
#include "LCD.h"
#define _XTAL_FREQ  4000000UL
#define correct 1
#define incorrect 0
char pw;
void Keypad2LCD_PrintName(char KEY,char *n);
void welcome(char KEY,char NAME[]);
void Name(char KEY,char NAME[]);
void Password(char NAME[],char _N);
char msg[20];
const char MARY_PW[10]=    {'P','4','2','1','8'};
const char JOHN_PW[10]=    {'Y','2','1','3','2','0','0','1'};
const char SUZAN_PW[10]= {'G','4','2','1','8'};
const char KELVIN_PW[10]=   {'H','2','0','0','0'};
char PW[10]={0};
void PS_Check(char n);
void main(void){
    char key;
    char N;
    char name[15]={0};
    char welcome_name[15]={0};
    
    LCD_Init();
    
    Keypad_Init();
    sprintf(msg,"Who Are You?");
    
   while(1){
       LCD_Clear();
      N=0;
      for(char i=0;i<15;i++){
      name[i]=0;
      welcome_name[i]=0;}
      
       for(char i=0;i<10;i++)
      PW[i]=0;
      key=0;
      
      LCD_GotoXY(0,1);
      LCD_Print(msg);
      LCD_GotoXY(0,3);
      LCD_Cursor(LCD_DISPLAY_ON|LCD_UNDERLINE_ON);
      
      while(key!=ENTER || N==0){
      key=Switch_Press_Scan();
     Keypad2LCD_PrintName(key,&N);
      Name(key,name);
      welcome(key,welcome_name);
      }
      LCD_Cursor(LCD_DISPLAY_ON|LCD_UNDERLINE_ON|LCD_BLINK_ON);
      key=0;
      Password(name,N);
      LCD_Cursor(LCD_DISPLAY_ON);
      if(pw==correct){
          LCD_Clear();
          LCD_GotoXY(0,1);
       LCD_Print("* * * WELCOME * * * ");
       LCD_GotoXY(0,3);
       LCD_Print(welcome_name);
          }

      if(pw==incorrect){
          LCD_Clear();
          LCD_GotoXY(0,1);
       LCD_Print("Your Password is");
       LCD_GotoXY(0,2);
       LCD_Print("Incorrect");
          }
      __delay_ms(1000);
      
  }
}
void Keypad2LCD_PrintName(char KEY,char *n){
    if(KEY!=ENTER|KEY!=DELETE){
        
         if(KEY=='H'){
             LCD_ClearLine(3);
             *n='H';
            LCD_Print("Kelvin");
        }
         if(KEY=='P'){
            LCD_ClearLine(3);
            *n='P';
            LCD_Print("Mary");
        }
         if(KEY=='Y'){
            LCD_ClearLine(3);
            *n='Y';
            LCD_Print("John");
        }
          if(KEY=='G'){
            LCD_ClearLine(3);
            *n='G';
            LCD_Print("Suzan");
        }
        LCD_GotoXY(0,3);
        }     
}
void Name(char KEY,char NAME[]){
    if(KEY=='G'){
        sprintf(NAME,"Suzan's");
    }
    if(KEY=='H'){
        sprintf(NAME,"Kelvin's");
    }
    if(KEY=='P'){
        sprintf(NAME,"Mary's");
    }
    if(KEY=='Y'){
        sprintf(NAME,"John's");
    }
}
   
void welcome(char KEY,char NAME[]){
    LCD_Cursor(LCD_DISPLAY_ON);
    if(KEY=='G'){
        sprintf(NAME,"Suzan");
    }
    if(KEY=='H'){
        sprintf(NAME,"Kelvin");
    }
    if(KEY=='P'){
        sprintf(NAME,"Mary");
    }
    if(KEY=='Y'){
        sprintf(NAME,"John");
    }
}
void Password(char NAME[],char _N){
    
    char i=0;
    LCD_Clear();
      LCD_GotoXY(0,1);
      LCD_Print("Write");
      LCD_GotoXY(0,2);
      LCD_Print(NAME);
      LCD_GotoXY(0,3);
      LCD_Print("Password");
      LCD_GotoXY(0,4);
      PS_Check(_N);
      
}

void PS_Check(char n){
  static  char Key=0;
    char i=0;
    char j;
     for(j=0;j<10;j++)
                PW[j]=0;
    while(Key!=ENTER){
        
        Key=Switch_Press_Scan();
        
        if(Key!=ENTER){
        PW[i]=Key;
        LCD_DataWrite(Key);
        
       i++;
        }
       
        if(i==10||Key==DELETE){
             LCD_ClearLine(4);
            i=0;
            for(j=0;j<10;j++)
                PW[j]=0;
        }
    }
    switch(n){
        case 'Y':for(j=0;j<10;j++){
            if(JOHN_PW[j]==PW[j])
                pw=correct;
            else if(JOHN_PW[j]!=PW[j]){
                pw=incorrect;
                j=10;
            }}
        break;
        case 'H':for(j=0;j<10;j++){
            if(KELVIN_PW[j]==PW[j])
                pw=correct;
            else if(KELVIN_PW[j]!=PW[j]){
                pw=incorrect;
                 j=10;
            }}
        break;
        case 'P':for( j=0;j<10;j++){
            if(MARY_PW[j]==PW[j])
                pw=correct;
            else if(MARY_PW[j]!=PW[j]){
                pw=incorrect;
                j=10;
            }}
        break;
        case 'G':for( j=0;j<10;j++){
            if(SUZAN_PW[j]==PW[j])
                pw=correct;
            else if(SUZAN_PW[j]!=PW[j]){
                pw=incorrect;
                j=10;
            }}
        break;    
        default:
            pw=incorrect;
            break;
    }
    Key=0;
}