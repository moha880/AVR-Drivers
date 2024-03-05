/*
 * main.c
 *
 *  Created on: Jul 16, 2022
 *      Author: Ibrahem
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include <util/delay.h>

//prebuild configuration

int main(void)
{


	DCM_t motor1={DIO_PORTA, DIO_PIN0,DIO_PIN1} ;
	DCM_t motor2=HDCM_xInit(DIO_PORTA, DIO_PIN0,DIO_PIN1) ;
	DCM_t motor3=HDCM_xInit(DIO_PORTA, DIO_PIN2,DIO_PIN7) ;


	HDCM_vRotateCW (&motor2);
	HDCM_vRotateCcW(&motor3);
	while(1){}
}
//	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	//	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	//	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	//MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);

	//while(1)
	//{

	//MDIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);
	//MDIO_vSetPinVal(DIO_PORTA,DIO_PIN1,DIO_HIGH);
	//MDIO_vSetPinVal(DIO_PORTA,DIO_PIN2,DIO_HIGH);
	//MDIO_vSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);


	//}

	u8 steps[]={9,1,3,2,6,4,12,8};

	MDIO_vSetPortDIR(DIO_PORTA,0X0F);
	while(1){
		for(u8 j=0;j<16;j++){
			for(u8 i=0 ; i<8;i++ ){

				MDIO_vSetPortVal(DIO_PORTA,steps[i]);
				_delay_ms(40);

			}
		}
	}
}
*/
