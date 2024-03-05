/*
 * ADC_prg.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Ibrahem
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_int.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"




void (*ADC_Callback)(void);
void (*ADC_Callback_2)(u16 A_u16ADC_Data);
u16* G_pu16ADC_Data;

FlagStatus_t xADCFlag =DOWN;


void MADC_vInit(void)
{
	/* 1- referance voltage selection */
#if ADC_REF_VOLT==AVCC
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif ADC_REF_VOLT==INTERNAL_REF
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif ADC_REF_VOLT==AREF
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#else
#error "PLEASE ENTER ONE OF THE OPTIONS"
#endif
	/* 2- data direction adjustment */
	CLR_BIT(ADMUX,ADLAR);
	/* 3- prescaler bits selection */
	ADCSRA = (ADCSRA & 0XF8 ) | ( ADC_PRESCALER );
	/* 4- auto trigger enable*/
	/* 4a auto trigger source*/
	CLR_BIT(ADCSRA,ADATE);
	/* 5-interrupt enable disable */
#if ADC_INTERUPT_VOLT==DISABLE
	CLR_BIT(ADCSRA,ADIE);
#elif ADC_INTERUPT_VOLT==ENABLE
	SET_BIT(ADCSRA,ADIE);
#endif
	/*  6-enable adc peripheral*/
	SET_BIT(ADCSRA,ADEN);


}
u16  MADC_u16AnalogRead(u8 A_u8ChannelNo ){

	/*1- select channel */
	ADMUX=(ADMUX & 0XE0) | (A_u8ChannelNo & 0X07);  //(A_u8ChannelNo & 0X1F)      DIFFERENTIAL
	/*2- start conversion */
	SET_BIT(ADCSRA,ADSC);
	/*3- poll on flag */
	while (GET_BIT(ADCSRA,ADIF) != 1){}
	/*4- clear flag */

	SET_BIT(ADCSRA,ADIF);

	/*5- return adc data */

	return ADC;


}
/*INTERUPT BASED APIs*/
void MADC_vStartConversion(u8 A_u8ChannelNo){
	/*1- select channel */
	ADMUX=(ADMUX & 0XE0) | (A_u8ChannelNo & 0X07);  //(A_u8ChannelNo & 0X1F)      DIFFERENTIAL
	/*2- start conversion */
	SET_BIT(ADCSRA,ADSC);
}
u16  MADC_u16GetADCData(void){

	/*5- return adc data */

	return ADC;

}
void MADC_vSetCallback(void(*A_fptr)(void)){

	ADC_Callback=A_fptr;
}

/*alternative method for the three top APIs*/

void MADC_vStartADCConversion_Asynch(u8 A_u8ChannelNo,
										u16* A_pu16ADCData,
											void(*A_fptr)(void) ){
	/*1- set callback function pointer */
	ADC_Callback = A_fptr;
	/*2- set adc data pointer */
	G_pu16ADC_Data = A_pu16ADCData;

	/*3- select channel */
	ADMUX=(ADMUX & 0XE0) | (A_u8ChannelNo & 0X07);  //(A_u8ChannelNo & 0X1F)      DIFFERENTIAL
	/*4- start conversion */
	SET_BIT(ADCSRA,ADSC);


}


FlagStatus_t   MADC_xGetFlagStatus(void){
	if(GET_BIT(ADCSRA,ADIF)==1){
		xADCFlag =UP;
	}
	return xADCFlag;
}

/*ADC_ISR*/

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if (G_pu16ADC_Data!=NULL)
	{
		*G_pu16ADC_Data=ADC; //FIRST U GET DATA THEN U EXCUTE CALLBACK MECHANISM
	}
	if (ADC_Callback!=NULL)
	{
//		ADC_Callback();
		ADC_Callback_2(ADC);

	}
	xADCFlag =UP;


}

