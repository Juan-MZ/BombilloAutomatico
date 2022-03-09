// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

uint8_t BCD_a_Decimal (uint8_t numero);
uint8_t Decimal_a_BCD (uint8_t numero);
char* Reloj_Calendario (static char Time[]);

#endif	/* XC_HEADER_TEMPLATE_H */

