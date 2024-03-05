################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KPD_prg.c \
../HAL/LCD_prg.c \
../HAL/SSD_prg.c 

OBJS += \
./HAL/KPD_prg.o \
./HAL/LCD_prg.o \
./HAL/SSD_prg.o 

C_DEPS += \
./HAL/KPD_prg.d \
./HAL/LCD_prg.d \
./HAL/SSD_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


