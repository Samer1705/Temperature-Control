/*
 ============================================================================
 Name        : main.c
 Author      : Samer Sameh Lawindy
 ============================================================================
 */

#include "atmega32_gpio.h"
#include "atmega32_adc.h"
#include "atmega32_interrupt.h"
#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "std_types.h"
#include <util/delay.h> /* To use the delay functions */


extern volatile uint8 g_setTemp = 30;
char g_temp;

void setFan(uint8 speed)
{
	LCD_moveCursor(2, 4);
	if(speed == 0) LCD_displayString("OFF ");
	else {
		LCD_intgerToString(speed);
		LCD_displayString("% ");
	}
	DcMotor_Rotate(CW, speed);
}
void displayTemp()
{
	g_temp =  LM35_getTemperature();
	LCD_moveCursor(1, 5);
	LCD_intgerToString(g_temp);
	LCD_displayCharacter(' ');
}
int main(void)
{
	ADC_ConfigType adc_config = { INTERNAL, DIV8 };
	DcMotor_Init();
	ADC_init(&adc_config);
	LCD_init();
	LCD_displayStringRowColumn(0, 0, "SET TEMP: ");
	LCD_displayStringRowColumn(1, 0, "TEMP: ");
	LCD_displayStringRowColumn(2, 0, "FAN: ");
	INTERRUPT_enable();
	INTERRUPT_INT0_init();
	INTERRUPT_INT1_init();
	while(1)
	{
		LCD_moveCursor(0, 9);
		LCD_intgerToString(g_setTemp);
		LCD_displayString("   ");
		displayTemp();
		if(g_temp < g_setTemp)
		{
			setFan(0);
		}
		else if (g_temp > g_setTemp && g_temp < g_setTemp*2)
		{
			setFan(25);
		}
		else if (g_temp > g_setTemp*2 && g_temp < g_setTemp*3)
		{
			setFan(50);
		}
		else if (g_temp > g_setTemp*3 && g_temp < g_setTemp*4)
		{
			setFan(75);
		}
		else if (g_temp > g_setTemp*4)
		{
			setFan(100);
		}
	}
}

