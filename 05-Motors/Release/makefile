################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
05-Motors.lss \

FLASH_IMAGE += \
05-Motors.hex \

EEPROM_IMAGE += \
05-Motors.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 05-Motors.elf secondary-outputs

# Tool invocations
05-Motors.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,05-Motors.map -mmcu=atmega32 -o "05-Motors.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

05-Motors.lss: 05-Motors.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 05-Motors.elf  >"05-Motors.lss"
	@echo 'Finished building: $@'
	@echo ' '

05-Motors.hex: 05-Motors.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 05-Motors.elf  "05-Motors.hex"
	@echo 'Finished building: $@'
	@echo ' '

05-Motors.eep: 05-Motors.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 05-Motors.elf  "05-Motors.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 05-Motors.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 05-Motors.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 05-Motors.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
