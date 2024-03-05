/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: Ibrahem
 */



#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"

int main(void)
{
	HLCD_vInit();
//	HLCD_vPrintNumber(1564);

	u8 heart[]={
				0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00,0x00
		};

	HLCD_vSaveCustomChar(1,heart);

	HLCD_vSetCursorPosition(4,1);

	HLCD_vDisplayCustomChar(1);

	while(1)
	{



	}

}
