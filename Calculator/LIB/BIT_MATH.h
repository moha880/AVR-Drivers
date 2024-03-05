/*
 * BIT_MATH.h
 *
 *  Created on: Jul 26, 2022
 *      Author: Ibrahem
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


#define SET_BIT(reg,bitnum)      	(reg|=(1<<bitnum))
#define CLR_BIT(reg,bitnum)			(reg&=~(1<<bitnum))
#define TOGGLE_BIT(reg,bitnum)      (reg^=(1<<bitnum))
#define GET_BIT(reg,bitnum)         (((reg)>>bitnum)& 0x01)
#define SET_BYTE(Reg,value)         ( Reg = value )



#endif /* LIB_BIT_MATH_H_ */
