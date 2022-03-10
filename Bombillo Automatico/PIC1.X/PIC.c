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
#include "RTC.h"
#include "I2C_Master_File.h"

void main(void) {
    char data_in;
    OSCCON = 0x72;
    ADCON1 = 0x0F;
    USART_Init(9600);
    I2C_Init();  
    TRISAbits.TRISA0 = 1;
    TRISB = 0;//salida
    LATB = 1;//Escritura PORTB Lectura
        //__delay_ms(20000);
    while(1) { 
        
        data_in = USART_ReceiveChar();
        if(data_in == '1'){
            LED = 1;
        }
        if(data_in == '2'){
            LED = 0;
        }
        while(data_in == '3'){
            if(SEN == 1){
                LED = 1;
            } else {
                LED = 0;
            }
        };
        if(data_in == '4'){
            do{
                if((RTC_Read_Hour(0) >= 17 && RTC_Read_Hour(0) <= 23)||(RTC_Read_Hour(0) >= 0 && RTC_Read_Hour(0) <= 6)){
                    LED = 1;
                }else {
                    LED = 0;
                }
            } while (data_in == '4');
        }
    }
    return;
}  
