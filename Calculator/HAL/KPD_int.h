/*
 * KPD_int.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Ibrahem
 */

#ifndef HAL_KPD_INT_H_
#define HAL_KPD_INT_H_

#define KPD_PORT DIO_PORTB


void HKPD_vInit(void);
u8 HKPD_u8GetPressedKey(u8 KPD_Map[][4]);



#endif /* HAL_KPD_INT_H_ */
