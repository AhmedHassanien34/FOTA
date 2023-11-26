/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 ROBOT								*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#include <stdio.h>

/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include "LIB/BIT_MATH.h"

/********************************************************************************************/
/* Include Interface Files in MCAL                                                          */
/********************************************************************************************/
#include "MCAL/GPIO/GPIO_interface.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "HAL/DCM/ROBOT_config.h"
#include "HAL/DCM/ROBOT_private.h"
#include "HAL/DCM/ROBOT_interface.h"


void ROBOT_voidInit(void)
{
	/************************************** MOTOR DRIVER L298******************************************************/
	GPIO_u8SetPinMode(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN1,GPIO_u8_OUTPUT_GP_PP_10MHZ);
	GPIO_u8SetPinMode(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN2,GPIO_u8_OUTPUT_GP_PP_10MHZ);
	GPIO_u8SetPinMode(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN3,GPIO_u8_OUTPUT_GP_PP_10MHZ);
	GPIO_u8SetPinMode(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN4,GPIO_u8_OUTPUT_GP_PP_10MHZ);
}



void ROBOT_voidForward(void)
{
	/* all motors forward */
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN1,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN2,GPIO_u8_HIGH);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN3,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN4,GPIO_u8_HIGH);
}

void ROBOT_voidBackward(void)
{
	/* all motors Backward */
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN1,GPIO_u8_HIGH);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN2,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN3,GPIO_u8_HIGH);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN4,GPIO_u8_LOW);
}

void ROBOT_voidRight(void)
{
	/* Left motors forward and Right motors Backward */
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN1,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN2,GPIO_u8_HIGH);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN3,GPIO_u8_HIGH);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN4,GPIO_u8_LOW);
}

void ROBOT_voidLeft(void)
{
	/* Left motors Backward and Right motors forward */
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN1,GPIO_u8_HIGH);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN2,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN3,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN4,GPIO_u8_HIGH);
}



void ROBOT_voidStop(void)
{
	/* Stop motors */
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN1,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN2,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN3,GPIO_u8_LOW);
	GPIO_u8WritePinValue(Robot_u8MOTOR_DRIVER_L298_PORT,Robot_u8MOTOR_DRIVER_L298_IN4,GPIO_u8_LOW);

}



