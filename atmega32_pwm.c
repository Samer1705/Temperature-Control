/******************************************************************************
 *	Module: ATMEGA32 PWM
 *	File Name: atmega32_pwm.c
 *  Description: ATMEGA32 PWM Driver Source File
 *  Author: Samer Sameh Lawindy
 *******************************************************************************/

#include "atmega32_pwm.h"
#include "common_macros.h"
#include <avr/io.h> /* To use the IO Ports Registers */

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCCR0 |= ((1<<WGM00) | (1<<WGM01)); /* Set Waveform Generation Mode to Fast PWM */
	TCCR0 |= (1<<COM01);				/* Set PWM Mode to Non-Inverted */
	OCR0 = (duty_cycle * 255) / 100;	/* Set PWM Duty Cycle */
	TCCR0 |= (1<<CS00);					/* Start PWM Timer With No Prescaler */
}
