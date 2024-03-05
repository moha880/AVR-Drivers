################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
06-EXTI-drivers.lss \

FLASH_IMAGE += \
06-EXTI-drivers.hex \

EEPROM_IMAGE += \
06-EXTI-drivers.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 06-EXTI-drivers.elf secondary-outputs

# Tool invocations
06-EXTI-drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,06-EXTI-drivers.map -mmcu=atmega32 -o "06-EXTI-drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

06-EXTI-drivers.lss: 06-EXTI-drivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 06-EXTI-drivers.elf  >"06-EXTI-drivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

06-EXTI-drivers.hex: 06-EXTI-drivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 06-EXTI-drivers.elf  "06-EXTI-drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

06-EXTI-drivers.eep: 06-EXTI-drivers.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 06-EXTI-drivers.elf  "06-EXTI-drivers.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 06-EXTI-drivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 06-EXTI-drivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 06-EXTI-drivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
