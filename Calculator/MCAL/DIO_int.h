/*
 * DIO_int.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_DIO_INT_H_
#define MCAL_DIO_INT_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


#define DIO_OUTPUT 1
#define DIO_INPUT  0

#define DIO_HIGH 1
#define DIO_LOW  0

void MDIO_vSetPinDIR(u8 A_u8PortNo , u8 A_u8PinNo , u8 A_u8Dir);
void MDIO_vSetPinVal(u8 A_u8PortNo , u8 A_u8PinNo , u8 A_u8Val);
u8   MDIO_u8GetPinVal(u8 A_u8PortNo , u8 A_u8PinNo);



void MDIO_vSetPortDIR(u8 A_u8PortNo , u8 A_u8Dir);
void MDIO_vSetPortVal(u8 A_u8PortNo , u8 A_u8Val);
u8   DIO_u8GetPortVal(u8 A_u8PortNo );

#endif /* MCAL_DIO_INT_H_ */
