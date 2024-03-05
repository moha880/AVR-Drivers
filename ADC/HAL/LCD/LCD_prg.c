/*
 * LCD_prg.c
 *
 *  Created on: Jul 20, 2022
 *      Author: Ibrahem
 */

#include <util/delay.h>


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_int.h"




void HLCD_vSendCommand(u8 A_u8Comand)
{

	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_LOW);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);
	MDIO_vSetPortVal(LCD_DATA_PORT , A_u8Comand);

	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);

	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN , DIO_LOW);
	_delay_ms(1);

}

void HLCD_vSendChar(u8 A_u8Char)
{

	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_HIGH);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);
	MDIO_vSetPortVal(LCD_DATA_PORT , A_u8Char);

	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);

	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN , DIO_LOW);
	_delay_ms(1);


}
void HLCD_vInit(void)
{

	//set pin direction
	MDIO_vSetPortDIR(LCD_DATA_PORT , 0XFF);
	MDIO_vSetPinDIR(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	MDIO_vSetPinDIR(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	MDIO_vSetPinDIR(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);

	//start init sequance

	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);
	_delay_ms(1);
	HLCD_vSendCommand(0b00001111);
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);
	_delay_ms(3);
	HLCD_vSendCommand(0b00000110);
	_delay_ms(1);

}
void HLCD_vPrintString(u8 A_u8string[])
{

	for (u8 L_u8i =0 ; A_u8string[L_u8i] !='\0' ;L_u8i++)
	{
		HLCD_vSendChar(A_u8string[L_u8i]);

	}


}

void HLCD_vPrintNumber(s32 A_s32Number)
{
	u8 L_u8Digits[10]={0};

	u8 L_u8Counter=0;

	//TODO negative number
	//TODO zero at the right

	while( A_s32Number > 0)
	{

		L_u8Digits[L_u8Counter] = A_s32Number%10+'0';
		L_u8Counter++;
		A_s32Number/=10;
	}
	/* print array in reverese  */
	for(s8 L_s8PrintIndex=L_u8Counter-1; L_s8PrintIndex >= 0; L_s8PrintIndex-- )
	{
		HLCD_vSendChar(L_u8Digits[L_s8PrintIndex]);
	}
}

void HLCD_vSetCursorPosition(u8 A_u8LinePos,u8 A_u8LineNo)
{
	switch(A_u8LineNo)
	{
	case LCD_LINE0:
		HLCD_vSendCommand(0x80+A_u8LinePos+0);
		break;
	case LCD_LINE1:
		HLCD_vSendCommand(0x80+A_u8LinePos+A_u8LineNo*64);
		break;
	}








}

void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_u8CustomCharData[] )
{
// 1  set cgram address

	HLCD_vSendCommand(0b01000000 + (A_u8CgramIndex*8) );
//2 send custom character data
	for (u8 L_u8Idx=0 ; L_u8Idx<8 ; L_u8Idx++)
	{

		HLCD_vSendChar(A_u8CustomCharData[L_u8Idx]);
	}
	//3   set ddram address
	HLCD_vSendCommand(0x80);

}

void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex)
{
	if (A_u8CgramIndex >=0 && A_u8CgramIndex < 8)
	{

		HLCD_vSendChar(A_u8CgramIndex);

	}

}


















