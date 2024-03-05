/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Ibrahem
 */
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"


int main(void){
/*
	DDRA  = 0x0f;//0b00001111; //PA0 -> Output

	while(1){
//		PORTA = 0b00000001; //PA0 -> High (5v)

	//	_delay_ms(1000);
		//PORTA = 0b00000000; //PA0 -> High (5v)
	//	_delay_ms(1000);
		PORTA = 0b00000001; //PA0 -> High (5v)

		for (int i=0 ; i<4;i++){
			_delay_ms(250);
			PORTA <<=1;

		}

	}
*/
	SET_BIT(DDRA,0);  //PA0 -> OUTPOUT 0b00000001
	CLR_BIT(DDRA,1);  //PA1 -> INPOUT  0b00000001
	SET_BIT(PORTA,1); //ENABLE PULL UP ON PA1 PORTA = 0b00000010
	if (GET_BIT(PINA,1)==0)
	{
		SET_BIT(PORTA,0);

	}
	else{
		CLR_BIT(PORTA,0);
	}


}



