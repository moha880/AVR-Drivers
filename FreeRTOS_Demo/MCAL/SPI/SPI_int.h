/*
 * SPI_int.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void MSPI_vInit(void);
u8   MSPI_u8Transmit__receive(u8 A_u8Data);


void   MSPI_u8Transmit(u8 A_u8Data);
u8   MSPI_u8receive(void);


#endif /* MCAL_SPI_SPI_INT_H_ */
