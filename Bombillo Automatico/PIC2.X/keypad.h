#ifndef keypad_H
#define keypad_H

#include <xc.h>
#include "pic18f4550.h"
#include "Config.h"

#define KeypadPORT PORTD
#define Keypad_dir TRISD

#define fila_1 PORTDbits.RD0    //A
#define fila_2 PORTDbits.RD1    //B
#define fila_3 PORTDbits.RD2    //C
#define fila_4 PORTDbits.RD3    //D

#define columna_1 0b00010000    //RD2 1
#define columna_2 0b00100000    //RD1 2
#define columna_3 0b01000000    //RD0 3

void Keypad_Init();
char Key_Press();

void Keypad_Init(){
    Keypad_dir = 0x0F;//entrada
}

char Key_Press(){
    char Key=0;
    KeypadPORT = columna_1;
    if(fila_1){
        Key=1;
    }
    if(fila_2){
        Key=4;
    }
    if(fila_3){
        Key=7;
    }
    if(fila_4){
        Key='*';
    }
    //__delay_ms(300);
    KeypadPORT = columna_2;
    if(fila_1){
        Key=2;
    }
    if(fila_2){
        Key=5;
    }
    if(fila_3){
        Key=8;
    }
    if(fila_4){
        Key=0;
    }
    //__delay_ms(300);
    KeypadPORT = columna_3;
    if(fila_1){
        Key=3;
    }
    if(fila_2){
        Key=6;
    }
    if(fila_3){
        Key=9;
    }
    if(fila_4){
        Key='#';
    }
    //__delay_ms(300);
    return Key;
}
#endif
