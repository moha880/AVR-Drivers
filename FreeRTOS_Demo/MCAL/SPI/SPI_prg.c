/*
 * SPI_prg.c
 *
 *  Created on: Aug 2, 2022
 *      Author: mazen
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"



void MSPI_vInit(void)
{
//SPI Serial Programming Waveforms  IN ATMEGA 32 THE IDLE STATE OF THE CLOCK IS 0   SO  CPOL BIT IN SPCR IS 0


	//	11010111    (FOUND ONLINE )
	u8 spcr_setting = 0b00000110;
	/* write your configurable code here */


	//INTERRUPT & POLLING
#if ACTIVATE_POLLING==INACTIVE
	spcr_setting |=   (1<<SPIE);
#elif ACTIVATE_POLLING==ACTIVE
	spcr_setting |=   (0<<SPIE);
#endif


	//ACtivate SPI
	spcr_setting |=   (1<<SPE);


	//DATA_ORDER
#if DATA_ORDER==LSB_FIRST
	spcr_setting |=(1<<DORD);

#elif DATA_ORDER==MSB_FIRST
	spcr_setting |=(0<<DORD);
#endif


	//Master/Slave Select

#if SPI_MODE==SPI_MASTER
	MDIO_vSetPinDIR(DIO_PORTB, DIO_PIN5, DIO_OUTPUT); // MOSI -> OUTPUT
	MDIO_vSetPinDIR(DIO_PORTB, DIO_PIN7, DIO_OUTPUT); // SCK -> OUTPUT
	MDIO_vSetPinDIR(DIO_PORTB, DIO_PIN6, DIO_INPUT); // MISO -> INPUT
	spcr_setting |=   (1<<MSTR);

#elif SPI_MODE==SPI_SLAVE

	MDIO_vSetPinDIR(DIO_PORTB, DIO_PIN5, DIO_INPUT); // MOSI -> INPUT
	MDIO_vSetPinDIR(DIO_PORTB, DIO_PIN7, DIO_INPUT); // SCK -> INPUT
	MDIO_vSetPinDIR(DIO_PORTB, DIO_PIN6, DIO_OUTPUT); // MISO -> OUTNPUT
	spcr_setting |=   (0<<MSTR);

#endif



	SPCR = spcr_setting ;

}

u8   MSPI_u8Transmit__receive(u8 A_u8Data)
{

	/* Start transmission */

	SPDR = A_u8Data;
	/* Wait for transmission complete */
#if ACTIVATE_POLLING==ACTIVE
	while(!(SPSR & (1<<SPIF)));
#endif
	return SPDR;
}



void   MSPI_u8Transmit(u8 A_u8Data){

	SPDR = A_u8Data;
#if ACTIVATE_POLLING==ACTIVE
	while(!(SPSR & (1<<SPIF)));
#endif

}
u8   MSPI_u8receive(void){

#if ACTIVATE_POLLING==ACTIVE
	while(!(SPSR & (1<<SPIF)));
#endif
	return SPDR;

}















