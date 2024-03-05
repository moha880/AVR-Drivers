/*
 * ADC_cfg.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/**
 * OPTIONS:
 *
 * 		INTERNAL_REF
 * 		AVCC
 * 		AREF
 *
 */
#define ADC_REF_VOLT	AVCC

/**
 * 		RIGHT/LIFT
 */

#define	ADC_ADJUST		RIGHT


/**
 * OPTIONS:
 *
 * 		ADC_PS_x    where x = 2 ,4 ,8 ,16 ,32 ,64 ,128
 *
 */

#define ADC_PRESCALER 	ADC_PS_8


/**
 * 		ENABLE/DISABLE
 */

#define ADC_INTERUPT_VOLT ENABLE

/**
 * 		ENABLE/DISABLE
 */


#define AUTO_TRIGGER DISABLE


/**
 * FREE_RUNNING
 * ANALOG_COMP
 * EXTI_INT
 * TIMER0_COMP
 * TIMER0_OV
 * TIMER_COMPB
 * TIMER1_OV
 * TIMER1_CAP_EVENT
 */

#define TRIGGER_SOURCE 	FREE_RUNNING

#endif /* MCAL_ADC_ADC_CFG_H_ */
