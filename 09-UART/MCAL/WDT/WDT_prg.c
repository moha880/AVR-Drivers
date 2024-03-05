/*
 * WDT_prg.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Ibrahem
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"


#include"WDT_int.h"
#include"WDT_prv.h"
#include"WDT_cfg.h"


void MWDT_vTurnOn(u8 A_u8Timeout){

	/* set timeout */

	WDTCR = (WDTCR& 0XF8) | A_u8Timeout;
	/* set WDE */

	SET_BIT(WDTCR,WDE);



}
void MWDT_vTurnOff(void){

	WDTCR = 0b0011000;
	WDTCR = 0;

}

