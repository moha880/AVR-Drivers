/*
 * main.c
 *
 *  Created on: Feb 1, 2023
 *      Author: Ibrahem
 */


#include"LIB/STD_TYPES.h"
#include"MCAL/DIO/DIO_int.h"
#include"FreeRTOS.h"
#include"task.h"

void Task_led1(void* pvParams){
	while (1){
		MDIO_vTogPinVal(DIO_PORTA,DIO_PIN0);
		vTaskDelay(50);
	}
}

void Task_led2(void* pvParams){
	while (1){
		MDIO_vTogPinVal(DIO_PORTA,DIO_PIN1);
		vTaskDelay(50);

	}
}

void Task_led3(void* pvParams){
	while (1){
		MDIO_vTogPinVal(DIO_PORTA,DIO_PIN2);
		vTaskDelay(100);
	}
}

int main (void){

	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	MDIO_vSetPinDIR(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);

	xTaskCreate(Task_led1,NULL,100,NULL,1,NULL);
	xTaskCreate(Task_led2,NULL,100,NULL,2,NULL);
	xTaskCreate(Task_led3,NULL,100,NULL,3,NULL);

	vTaskStartScheduler();
}

