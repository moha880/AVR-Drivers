/*
 * main.c
 *
 *  Created on: Jul 28, 2022
 *      Author: Ibrahem
 */
#include <avr/io.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO_int.h"
#include "../HAL/KPD_int.h"
#include "../HAL/LCD_int.h"


int main(void)
{
	u8 KPD_Map[4][4] =
	{
			{1,2,3,'4'},
			{'5','6','7','8'},
			{'9','1','1','2'},
			{'+','-','*','/'}
	};


	HKPD_vInit();
	u8 key =0;
	DDRC=255;

	PORTC=0b00100111;

	while(1){

		key = HKPD_u8GetPressedKey(KPD_Map);
		switch(key){
		case 1 :

			PORTC=0b00000110;
			break;
		case 2 :
			PORTC=0b01011011;
			break;
		case 3 :
			PORTC=0b01001111;
			break;
		case 4 :
			PORTC=0b01100110;
			break;
		case 5 :
			PORTC=0b01101101;
			break;
		case 6 :
			PORTC=0b01111101;
			break;
		case 7 :
			PORTC=0b00000111;
			break;
		case 8 :
			PORTC=0b01111111;
			break;
		case 9 :
			PORTC=0b01101111;
			break;
		default:
			PORTC=0b00111111;
			break;
		}
	}

}



