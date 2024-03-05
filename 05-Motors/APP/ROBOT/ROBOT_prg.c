/*
 * ROBOT_prg.c
 *
 *  Created on: Aug 18, 2022
 *      Author: Ibrahem
 */


#include"../../LIB/STD_TYPES.h"

#include"../../HAL/DCM/DCM_int.h"
#include"../../MCAL/DIO/DIO_int.h"

#include"ROBOT_int.h"
#include"ROBOT_cfg.h"

DCM_t xFrontRightMotor;
DCM_t xFrontLeftMotor;
DCM_t xRearRightMotor;
DCM_t xRearLefttMotor;


void ROBOT_vInit(void)
{
	xFrontRightMotor =HDCM_xInit(FRONT_RIGHT_MOTOR_PORT ,FRONT_RIGHT_MOTOR_PIN1, FRONT_RIGHT_MOTOR_PIN2);
	xFrontLeftMotor = HDCM_xInit(FRONT_LEFT_MOTOR_PORT  ,FRONT_LEFT_MOTOR_PIN1,  FRONT_LEFT_MOTOR_PIN2);
	xRearRightMotor = HDCM_xInit(REAR_RIGHT_MOTOR_PORT  ,REAR_RIGHT_MOTOR_PIN1,  REAR_RIGHT_MOTOR_PIN2);
	xRearLefttMotor = HDCM_xInit(REAR_LEFT_MOTOR_PORT   ,REAR_LEFT_MOTOR_PIN1,   REAR_LEFT_MOTOR_PIN2);


}
void ROBOT_vMoveForward(void){



}
void ROBOT_vMoveBackward(void){}
void ROBOT_vHalt(void){}
void ROBOT_vSteer(u8 A_uAngle, u8 A_u8Dir){}

