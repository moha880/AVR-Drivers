/*
 * main.c
 *
 *  Created on: Jun 2, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include"../HAL/LCD/LCD_int.h"
#include"../MCAL/GIE/GIE_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include  <util/delay.h>

volatile u16 adc_value = 0;   //shared between isr and main or any other functions  so its rarely to be called
volatile u16 adc_readings[5];
volatile u8 adc_flag = 0;   //shared between isr and main or any other functions  so its rarely to be called
volatile u8 adc_idx=0;

void adc_isr(void)
{
	adc_value= MADC_u16GetADCData();
	MADC_vStartConversion(CHANNEL_00);
	adc_flag=1;
}
/*

void adc_isr(u16 A__u16ADCData)
{
	adc_readings[adc_idx]= A__u16ADCData;
	adc_idx++;

	you can change the channel to read many readings


}
*/


int main(void)
{

	MADC_vSetCallback(adc_isr);
	MADC_vInit();
	HLCD_vInit();

	//u16 adc_value=0;
	MADC_vStartConversion(CHANNEL_00);

	MGIE_vEnableGlobalInterrupt();

	while(1)
	{
		//adc_value = MADC_u16AnalogRead(CHANNEL_00);
		if(adc_flag==1){
			HLCD_vSendCommand(LCD_CLEAR);
			HLCD_vPrintNumber(adc_value);
			MADC_vStartConversion(CHANNEL_00);
			_delay_ms(250);

		}
	}
}
