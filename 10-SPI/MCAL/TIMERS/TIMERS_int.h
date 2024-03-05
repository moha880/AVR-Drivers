/*
 * TIMERS_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: mazen
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_

#define TIM_CB_OVF		0
#define TIM_CB_CTC		1



#define TIMER0			0
#define TIMER_1A		1
#define TIMER1			2

typedef enum
{
	ICU_Falling,
	ICU_Rising
}ICU_Trigger_t;


void MTIMERS_vInit(void);

void MTIMERS_vSetPreloadValue(u8 A_u8TimerId ,u16 A_u16Preload);

void MTIMERS_vSetCompareValue(u8 A_u8TimerId ,u16 A_u16CompareValue);

void MTIMERS_vSetInterval_Asynch(u16 A_u16IntervalCounts, void (*A_fptr)(void));

void MTIMERS_vSetInterval_CTC_Asynch(u16 A_u16IntervalCounts,
									u16 A_u16CompareValue,
									void (*A_fptr)(void));

u16 MTIMERS_u16GetElapsedTime(u8 A_u8TimerId);
u16 MTIMERS_u16GetCapturedTme(void);
void MTIMERS_vSetIcuTrigger(ICU_Trigger_t A_xIcuTrigger);
void MTIMERS_vEnableInterrupt(/* Timer ID ? u8 A_u8InterruptType*/);
void MTIMERS_vDisableInterrupt(/* Timer ID ?*/ u8 A_u8InterruptType);


void MTIMERS_vSetCallback( /* Timer ID ?*/ );

void MTIMERS_vStartTimer(/* Timer ID ?*/) ;

void MTIMERS_vStopTimer(/* Timer ID ?*/) ;

#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
