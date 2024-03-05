/*
 * TIMERS_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "TIMERS_int.h"
#include "TIMERS_prv.h"
#include "TIMERS_cfg.h"

static void (*G_TIM0_OVF_Callback)(void);
static void (*G_TIM0_CTC_Callback)(void);
static void (*GS_TIM1_ICU_Callback)(void);

//static void (*G_TIM0_Callback[2])(void);

u32  G_u32IntervalCount;

void MTIMERS_vInit(void)
{
	/**
	 * Mode: Normal Overflow
	 * Interrupt: enable OVerflow intterupt
	 * Prescaler: No CLOCK -> timer stopped
	 */
#if TIMER0_ENABLE==ENABLE
	/*1- Wave Generation Mode */
#if TIMER0_MODE==TIMER_OVF
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
#elif TIMER0_MODE==TIMER_CTC
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
#elif TIMER0_MODE==TIMER_FASTPWM
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
#elif TIMER0_MODE==TIMER_PHASECORRECT
	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
#else
#error "Please select a valid Timer Mode"
#endif

	/*2- Compare Match mode  */

	/*3- Interrupt enable   */

#endif

#if TIMER1_ENABLE==ENABLE

#endif



    TCCR0 = 0b01101010;
//	SET_BIT(TIMSK, 0) ; //TOIE0
//	SET_BIT(TIMSK, 1) ; //OCIE0
  	TCCR1A= 0b10000000 ;
  	TCCR1B= 0b01000010 ;
// 	ICR1  = 625;  //	20ms

}

void MTIMERS_vSetPreloadValue(u8 A_u8TimerId , u16 A_u16Preload)
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		TCNT0 = A_u16Preload ;
		break;
	}
}
void MTIMERS_vSetCompareValue(u8 A_u8TimerId ,u16 A_u16CompareValue)
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		OCR0 = A_u16CompareValue ;
		break;
	case TIMER_1A:
		OCR1A = A_u16CompareValue ;
		break;
	}
}
void MTIMERS_vSetInterval_Asynch(u16 A_u16IntervalCounts, void (*A_fptr)(void))
{
	G_u32IntervalCount = A_u16IntervalCounts ;
	G_TIM0_OVF_Callback = A_fptr ;
//	G_TIM0_Callback[TIM_CB_OVF] = A_fptr ;

	/*  start timer */
	MTIMERS_vStartTimer();

}

void MTIMERS_vSetInterval_CTC_Asynch(u16 A_u16IntervalCounts,
									u16 A_u16CompareValue,
									void (*A_fptr)(void))
{
	G_u32IntervalCount = A_u16IntervalCounts ;
	G_TIM0_CTC_Callback = A_fptr ;
//	G_TIM0_Callback[TIM_CB_CTC] = AfPtr;

//	MTIMERS_vSetCompareValue(A_u16CompareValue);
	/*  start timer */
	MTIMERS_vStartTimer();

}

void MTIMERS_vStartTimer(/* Timer ID ?*/)
{
	TCCR0 = (TCCR0 & 0xF8) | (TIMER0_PRESCALER) ;
}

void MTIMERS_vStopTimer(/* Timer ID ?*/)
{
	TCCR0 = (TCCR0 & 0xF8) | (0b000) ;
}





u16 MTIMERS_u16GetElapsedTime(u8 A_u8TimerId)
{

	u16 L_u16ElapsedTime =0 ;
	switch(A_u8TimerId)
	{
	case TIMER0:
		L_u16ElapsedTime =TCNT0;
		break;
	case TIMER1:
		L_u16ElapsedTime =TCNT1;
		break;

	}

	return L_u16ElapsedTime;

}

u16 MTIMERS_u16GetCapturedTme(void){
	return ICR1;

}


void MTIMERS_vSetIcuTrigger(ICU_Trigger_t A_xIcuTrigger){

	switch(A_xIcuTrigger){
	case ICU_Falling:
		CLR_BIT(TCCR1B,6); //ICES
		break;
	case ICU_Rising:
		SET_BIT(TCCR1B,6);
		break;

	}

}
void MTIMERS_vEnableInterrupt()/* Timer ID ?*/ //u8 A_u8InterruptType){
{
	SET_BIT(TIMSK,5);
}
void MTIMERS_vDisableInterrupt(/* Timer ID ?*/ u8 A_u8InterruptType){
	CLR_BIT(TIMSK,5);

}
void MTIMERS_vSetCallback( /* Timer ID ?*/ void (*A_xfptr)(void))
{
	GS_TIM1_ICU_Callback=A_xfptr;
}


/* Timer 0 Overflow ISR */
void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	static u32 LS_u32Counter = 0;

	LS_u32Counter++ ;

	if(LS_u32Counter == G_u32IntervalCount)
	{
		if(G_TIM0_OVF_Callback != NULL)
		{
			G_TIM0_OVF_Callback();
			LS_u32Counter = 0;
		}
	}
}

/* Timer 0 CTC ISR */
void __vector_10(void) __attribute__((signal))  ;
void __vector_10(void)
{
	static u32 LS_u32Counter = 0;

	LS_u32Counter++ ;

	if(LS_u32Counter == G_u32IntervalCount)
	{
		if(G_TIM0_CTC_Callback != NULL)
		{
			G_TIM0_CTC_Callback();
			LS_u32Counter = 0;
		}
	}
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	GS_TIM1_ICU_Callback();
}













