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
#error "PLEASE ENTER ONE OF THE ADC_REF_VOLT OPTIONS"
#endif



	/* 2- data direction adjustment */
#if ADC_ADJUST==RIGHT
	CLR_BIT(ADMUX,ADLAR);
#elif ADC_ADJUST==LIFT
	SET_BIT(ADMUX,ADLAR);
#else
#error "PLEASE ENTER ONE OF THE ADC_ADJUST OPTIONS"
#endif



	/* 3- prescaler bits selection */
	ADCSRA = (ADCSRA & 0XF8 ) | ( ADC_PRESCALER );


	/* 4- auto trigger enable*/
#if AUTO_TRIGGER==ENABLE
	SET_BIT(ADCSRA,ADATE);
	/* 4a auto trigger source*/
	SFIOR = (SFIOR & 0X1F) | (TRIGGER_SOURCE << 5 );

#elif AUTO_TRIGGER==DISABLE
	CLR_BIT(ADCSRA,ADATE);
#else
#error "PLEASE ENTER ONE OF THE AUTO_TRIGGER OPTIONS"
#endif




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




void MADC_vStartConversion(u8 A_u8ChannelNo){
	/*1- select channel */
	ADMUX=(ADMUX & 0XE0) | (A_u8ChannelNo & 0X07);  //(A_u8ChannelNo & 0X1F)      DIFFERENTIAL
	/*2- start conversion */
	SET_BIT(ADCSRA,ADSC);
}


u16	MADC_u16GetADCData(void){

	return ADC;

}

void MADC_vSetCallback(void(*A_fptr)(void)){

	ADC_Callback = A_fptr;
}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{

	ADC_Callback();
}














