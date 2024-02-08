/******************************************************************************
 *	Module: ATMEGA32 PWM
 *	File Name: atmega32_pwm.h
 *  Description: ATMEGA32 PWM Driver Header File
 *  Author: Samer Sameh Lawindy
 *******************************************************************************/

#ifndef ATMEGA32_PWM_H_
#define ATMEGA32_PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* ATMEGA32_PWM_H_ */
