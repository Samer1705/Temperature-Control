/******************************************************************************
 *	Module: DC MOTOR
 *	File Name: dc_motor.h
 *  Description: DC Motor Driver Header File
 *  Author: Samer Sameh Lawindy
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "atmega32_gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DcMotor_PIN1_PORT_ID PORTB_ID
#define DcMotor_PIN2_PORT_ID PORTB_ID
#define DcMotor_PIN1_PIN_ID	PIN0_ID
#define DcMotor_PIN2_PIN_ID	PIN1_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	STOP, CW, ACW
}DcMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
