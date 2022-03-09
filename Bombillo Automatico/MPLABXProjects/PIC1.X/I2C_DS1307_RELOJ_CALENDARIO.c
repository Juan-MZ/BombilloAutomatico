/* :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::                                      ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::         PIC18F4550        ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::           I2C DS1307        ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::                 LCD              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::: RELOJ CALENDARIO ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::: Autor: Jorge Peralta C.  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::: Canal youtube: Jorge APC   :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::                                        ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*==========================================================================================================
 ===========================================================================================================*/
#include "Config.h"            // Incluimos los bits de configuraci�n.
#include "I2C_librery.h"                   // Incluimos la librer�a I2C.
#include "reloj_header.h"
#include <stdio.h>                         // Incluimos la librer�a stdio.
#include <stdint.h>                        // Incluimos la librer�a stdint.

/*==========================================================================================================
 ===========================================================================================================*/
uint8_t hours;                             // Variable de 8 bits para las horas.
uint8_t minutes;                           // Variable de 8 bits para los minutos.
uint8_t seconds;                           // Variable de 8 bits para los segundos.
uint8_t year;                              // Variable de 8 bits para los a�o.
uint8_t month;                             // Variable de 8 bits para el mes.
uint8_t day;                               // Variable de 8 bits para el dia.
uint8_t i;                                 // Variable de 8 bits.
 

/*==========================================================================================================
 ===========================================================================================================*/
uint8_t BCD_a_Decimal (uint8_t numero)            // Funci�n que convierte un n�mero BCD a decimal.
{
  return ((numero >> 4) * 10 + (numero & 0x0F));  // Retornamos la variable "numero" desplazado 4 posiciones a la izquierda, multiplicado por 10 m�s "numero" &&  1111.
}

/*==========================================================================================================
 ===========================================================================================================*/
uint8_t Decimal_a_BCD (uint8_t numero)            // Funci�n que convierte un n�mero decimal a BCD. 
{
    return (((numero / 10) << 4) + (numero % 10));// Retornamos la decena de la variable "numero" desplazado 4 bits a la derecha y las unidades de la variable "numero" en el nibble menos significativo
}

/*==========================================================================================================
 ===========================================================================================================*/
char* Reloj_Calendario (static char Time[])                //Funci�n de visualizaci�n de HORA Y FECHA.
{
    Time[] = "TIME: 00:00:00";  // Arreglo est�tico char "Time". 
    static char Date[] = "DATE: 00/00/2000";// Arreglo est�tico char "Date".
  
    seconds = BCD_a_Decimal(seconds);       // Llamamos a la funci�n de conversi�n de BCD a Decimal.
    minutes = BCD_a_Decimal(minutes);       // Llamamos a la funci�n de conversi�n de BCD a Decimal.
    hours   = BCD_a_Decimal(hours);         // Llamamos a la funci�n de conversi�n de BCD a Decimal.
    day     = BCD_a_Decimal(day);           // Llamamos a la funci�n de conversi�n de BCD a Decimal.
    month   = BCD_a_Decimal(month);         // Llamamos a la funci�n de conversi�n de BCD a Decimal.
    year    = BCD_a_Decimal(year);          // Llamamos a la funci�n de conversi�n de BCD a Decimal.
    
    Time[6] =  hours   / 10 + '0';          // Guardamos las decenas de la variable "hours" en la posici�n 6 del arreglo "Time".
    Time[7] =  hours   % 10 + '0';          // Guardamos las unidades de la variable "hours" en la posici�n 7 del arreglo "Time".
    Time[9] =  minutes / 10 + '0';          // Guardamos las decenas de la variable "minutes" en la posici�n 9 del arreglo "Time".
    Time[10]=  minutes % 10 + '0';          // Guardamos las unidades de la variable "minutes" en la posici�n 10 del arreglo "Time".
    Time[12]=  seconds / 10 + '0';          // Guardamos las decenas de la variable "seconds" en la posici�n 12 del arreglo "Time".
    Time[13]=  seconds % 10 + '0';          // Guardamos las unidades de la variable "secods" en la posici�n 13 del arreglo "Time".
    
    Date[6] =  day     / 10 + '0';          // Guardamos las decenas de la variable "day" en la posici�n 6 del arreglo "Date".
    Date[7] =  day     % 10 + '0';          // Guardamos las unidades de la variable "day" en la posici�n 7 del arreglo "Date".
    Date[9] =  month   / 10 + '0';          // Guardamos las decenas de la variable "month" en la posici�n 9 del arreglo "Date".
    Date[10]=  month   % 10 + '0';          // Guardamos las unidades de la variable "month" en la posici�n 10 del arreglo "Date".
    Date[14]=  year    / 10 + '0';          // Guardamos las decenas de la variable "year" en la posici�n 14 del arreglo "Date".
    Date[15]=  year    % 10 + '0';          // Guardamos las unidades de la variable "year" en la posici�n 15 del arreglo "Date".
    return Time;
}
