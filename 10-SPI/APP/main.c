/*
 * main.c
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/GIE/GIE_int.h"




#include <avr/io.h>
#include <avr/interrupt.h>


ISR(SPI_STC_vect)
{
	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);

}



int main(void)
{

	MGIE_vEnableGlobalInterrupt();
	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	MSPI_vInit();
	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);

	u8 c;

	MSPI_u8Transmit(5);
	c=MSPI_u8receive();




	while(1)
	{

	}
}











