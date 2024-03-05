/*
 * UART_prg.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Ibrahem
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "UART_int.h"
#include "UART_prv.h"
#include "UART_cfg.h"

void MUART_vInit(void)
{
	UCSRB = 0b00011000 ;
	UCSRC = 0b10000110 ;
	UBRRL=51; 		//9600
}
void MUART_vTransmit(u8 A_u8Byte){

	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;
}

u8 MUART_u8Recieve(void){

	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;

}
