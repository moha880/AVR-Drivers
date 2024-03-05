/*
 * SPI_prv.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPIF		7



#define SPCR	*((volatile u8*)(0x2D))
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7


#define SPSR		*((volatile u8*)(0x2E))
#define SPDR		*((volatile u8*)(0x2F))










#define SPI_MASTER  1
#define SPI_SLAVE   2


#define ACTIVE  3
#define INACTIVE  4


#define MSB_FIRST  5
#define LSB_FIRST  6


#endif /* MCAL_SPI_SPI_PRV_H_ */
