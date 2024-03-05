/*
 * main.c
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_int.h"

#include "../MCAL/GIE/GIE_int.h"

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	MDIO_vTogPinVal(DIO_PORTA, DIO_PIN0);
}



int main(void)
{
	MDIO_vSetPinDIR(DIO_PORTD, DIO_PIN2 ,DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTD, DIO_PIN2, DIO_HIGH); // enable pull up resistor on PD2
	MDIO_vSetPinDIR(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	MEXTI_vInit();

	MGIE_vEnableGlobalInterrupt();
	while(1)
	{

	}
}
