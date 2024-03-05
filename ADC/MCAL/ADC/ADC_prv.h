/*
 * ADC_prv.h
 *
 *  Created on: Sep 4, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_



#define AVCC		1
#define AREF		2
#define INTERNAL_REF	3

#define RIGHT		1
#define LIFT		0



#define ADC_PS_2	0b001
#define ADC_PS_4	0b010
#define ADC_PS_8	0b011




#define	DISABLE		0
#define	ENABLE		1



#define FREE_RUNNING		0b000
#define ANALOG_COMP			0b001
#define EXTI_INT			0b010
#define TIMER0_COMP			0b011
#define TIMER0_OV			0b100
#define TIMER_COMPB			0b101
#define TIMER1_OV			0b110
#define TIMER1_CAP_EVENT	0b111





#define ADMUX		*((volatile u8*)(0x27))
#define ADCSRA		*((volatile u8*)(0x26))
#define ADCL		*((volatile u8*)(0x24))
#define ADCH		*((volatile u8*)(0x25))
#define SFIOR		*((volatile u8*)(0x50))




#define REFS1		7
#define REFS0		6
#define ADSC		6
#define ADLAR		5
#define ADATE		5
#define ADIE		3
#define ADIF		4
#define ADEN		7




#define ADC			*((volatile u16*)(0x24))



#endif /* MCAL_ADC_ADC_PRV_H_ */
