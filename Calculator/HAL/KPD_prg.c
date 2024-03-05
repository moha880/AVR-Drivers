/*
 * KPD_prg.c
 *
 *  Created on: Jul 28, 2022
 *      Author: Ibrahem
 */

#include <avr/io.h>
#include <util/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO_int.h"

#include "KPD_int.h"



void HKPD_vInit(void)
{
	MDIO_vSetPortDIR(KPD_PORT,0xf0);
	MDIO_vSetPortVal(KPD_PORT,0xff);
}

u8 HKPD_u8GetPressedKey(u8 KPD_Map[][4])
{
	u8 L_u8Pressed=0;


	for(u8 cols = 0 ; cols<=3 ;cols++)
	{
		MDIO_vSetPinVal(KPD_PORT,cols+4,DIO_LOW);

		for(u8 rows=0; rows<=3;rows++)
		{

			if (MDIO_u8GetPinVal(KPD_PORT,rows)==0)
			{
				L_u8Pressed=KPD_Map[rows][cols];
			}

			while(MDIO_u8GetPinVal(KPD_PORT,(rows))==0){}
			_delay_ms(10);

		}
		MDIO_vSetPinVal(KPD_PORT,cols+4,DIO_HIGH);

	}


	return L_u8Pressed;
}

