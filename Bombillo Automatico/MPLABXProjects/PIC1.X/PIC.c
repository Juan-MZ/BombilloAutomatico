/*
 * File:   PIC.c
 * Author: JARMX
 *
 * Created on 8 de marzo de 2022, 08:50 PM
 */

#include <pic18f4550.h>
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "led.h"
#include "Config.h"
#include "USART_Header_File.h"

void main(void) {
    char data_in;
    ADCON1 = 0x0F;
    USART_Init(9600);
    TRISAbits.TRISA0 = 1;
    TRISB = 0;//salida
    LATB = 1;//Escritura PORTB Lectura
        //__delay_ms(20000);
    while(1) { 
        data_in = USART_ReceiveChar();
        if(data_in == '1'){
            LED = 1;
        }else if(data_in == '2'){
            LED = 0;
        }else if(data_in == '3'){
            if(SEN == 1){
                LED = 1;
            }else {
                LED = 0;
            }
            __delay_ms(300); 
        } else if(data_in == '4'){
            char* Time[] = Reloj_Calendario (Time[]);
        }
    }
            
    }
    
  
  return;
}
