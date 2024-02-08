/******************************************************************************
 *	Module: DC MOTOR
 *	File Name: dc_motor.c
 *  Description: DC Motor Driver Source File
 *  Author: Samer Sameh Lawindy
 *******************************************************************************/

#include "dc_motor.h"
#include "atmega32_pwm.h"
#include "common_macros.h"
#include <avr/io.h> /* To use the IO Ports Registers */

/* Set DC Motor Pins Directions */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DcMotor_PIN1_PORT_ID, DcMotor_PIN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_PIN2_PORT_ID, DcMotor_PIN2_PIN_ID, PIN_OUTPUT);
}

/* Set DC Motor State (Clockwise, Anti-Clockwise, Stop) & Rotation Speed */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start(speed);
	switch(state)
	{
	case CW:
		GPIO_writePin(DcMotor_PIN1_PORT_ID, DcMotor_PIN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DcMotor_PIN2_PORT_ID, DcMotor_PIN2_PIN_ID, LOGIC_LOW);
		break;
	case ACW:
		GPIO_writePin(DcMotor_PIN1_PORT_ID, DcMotor_PIN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_PIN2_PORT_ID, DcMotor_PIN2_PIN_ID, LOGIC_HIGH);
		break;
	case STOP:
	default:
		GPIO_writePin(DcMotor_PIN1_PORT_ID, DcMotor_PIN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_PIN2_PORT_ID, DcMotor_PIN2_PIN_ID, LOGIC_LOW);
		break;

	}
}
