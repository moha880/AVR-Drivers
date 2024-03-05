/*
 * TIMERS_cfg.h
 *
 *  Created on: Jul 19, 2022
 *      Author: mazen
 */

#ifndef MCAL_TIMERS_TIMERS_CFG_H_
#define MCAL_TIMERS_TIMERS_CFG_H_


/* ---------- Timer 0 Configurations ----------- */

#define TIMER0_ENABLE		DISABLE

/**
 * Options:
	 * TIMER_OVF
	 * TIMER_CTC
	 * TIMER_FASTPWM
	 * TIMER_PHASECORRECT
 */
#define TIMER0_MODE   TIMER_OVF
#define TIMER0_PRESCALER	TIMER_PS_8

/* ---------- Timer 1 Configurations ----------- */


#endif /* MCAL_TIMERS_TIMERS_CFG_H_ */
