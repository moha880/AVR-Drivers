/*
 * main.c
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/WDT/WDT_int.h"

#include <util/delay.h>
int main(void)
{
	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);


	MWDT_vTurnOn(WDT_1s);
	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
	_delay_ms(500);
	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);
	while(1)
	{

	}
}











