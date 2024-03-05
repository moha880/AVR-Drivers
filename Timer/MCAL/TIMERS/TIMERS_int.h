/*
 * TIMERS_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: mazen
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_












void MTIMER_vInit(void);
void MTIMER_vSetPreload(void);
void MTIMER_vStartTimer(void);
void MTIMERS_vStopTimer(/* Timer ID ?*/) ;

void MTIMERS_vSetInterval_Asynch(u16 A_u16IntervalCounts, void (*A_fptr)(void));
void MTIMERS_vSetCallback( );



#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
