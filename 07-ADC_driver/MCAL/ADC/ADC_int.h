/*
 * ADC_int.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Ibrahem
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define CHANNEL_00 0
#define CHANNEL_01 1
#define CHANNEL_02 2
#define CHANNEL_03 3
#define CHANNEL_04 4
#define CHANNEL_05 5
#define CHANNEL_06 6
#define CHANNEL_07 7

typedef enum{

	UP,
	DOWN

}FlagStatus_t;

void MADC_vInit();
u16  MADC_u16AnalogRead(u8 A_u8ChannelNo );

/* INTERUPT BASED APIs */
void MADC_vStartConversion(u8 A_u8ChannelNo);
u16  MADC_u16GetADCData(void);
void MADC_vSetCallback(void(*A_fptr)(void));
void MADC_vSelectChannel(u8 A_u8ChannelNo);
/* alternative method */
void MADC_vStartADCConversion_Asynch(u8 A_u8ChannelNo,
										u16* A_pu16ADCData,
											void(*A_fptr)(void));
FlagStatus_t   MADC_xGetFlagStatus(void);

#endif /* MCAL_ADC_ADC_INT_H_ */
