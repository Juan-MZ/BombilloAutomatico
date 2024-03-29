/*
 * File:   LED.c
 * Author: JARMX
 *
 * Created on 8 de marzo de 2022, 03:29 PM
 */

// Se incluye las librerias necesarias para el funcionamiento del programa 
#include "led.h"
#include "keypad.h"
#include "USART_Header_File.h"
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

//definir la frecuencia del oscilador 
//#define _XTAL_FREQ 48000000

void main(void) {
    /* */
    char auxvalor=0;
    char tecla;
    OSCCON = 0x72;
    ADCON1 = 0x0F; //entrada
    TRISB = 0x00; //salida
    USART_Init(9600);
    Keypad_Init();
    while(1){
        tecla = Key_Press();
        if(tecla==1){
            auxvalor=1;
            USART_TxChar('1');
        }else if (tecla ==2){
            auxvalor=2;
            USART_TxChar('2');
        }else if (tecla==3){
            auxvalor=3;
            USART_TxChar('3');
        } else if (tecla==4){
            auxvalor=4;
            USART_TxChar('4');
        } else {
            USART_TxChar(0);
        }
        if(auxvalor==1){
            LED = 1;
        }else{
            LED = 0;
        }
    }
     
    
}


