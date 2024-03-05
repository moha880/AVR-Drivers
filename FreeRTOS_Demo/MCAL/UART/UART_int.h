/*
 * UART_int.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_vInit(void);
void MUART_vTransmit(u8 A_u8Byte);
u8 MUART_u8Recieve(void);

#endif /* MCAL_UART_UART_INT_H_ */
