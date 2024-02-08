################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../atmega32_adc.c \
../atmega32_gpio.c \
../atmega32_interrupt.c \
../atmega32_pwm.c \
../dc_motor.c \
../lcd.c \
../lm35_sensor.c \
../main.c 

OBJS += \
./atmega32_adc.o \
./atmega32_gpio.o \
./atmega32_interrupt.o \
./atmega32_pwm.o \
./dc_motor.o \
./lcd.o \
./lm35_sensor.o \
./main.o 

C_DEPS += \
./atmega32_adc.d \
./atmega32_gpio.d \
./atmega32_interrupt.d \
./atmega32_pwm.d \
./dc_motor.d \
./lcd.d \
./lm35_sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


