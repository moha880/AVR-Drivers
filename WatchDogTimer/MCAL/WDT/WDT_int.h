/*
 * WDT_int.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_WDT_WDT_INT_H_
#define MCAL_WDT_WDT_INT_H_


#define WDT_16ms	0b000
#define WDT_32ms	0b001
#define WDT_65ms	0b010
#define WDT_130ms	0b011
#define WDT_260ms	0b100
#define WDT_520ms	0b101
#define WDT_1s		0b110
#define WDT_2s		0b111


void MWDT_vTurnOn(u8 A_u8Timeout);
void MWDT_vTurnOff(void);


#endif /* MCAL_WDT_WDT_INT_H_ */
