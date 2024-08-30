################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/SOLENOID/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/BUZZER/subdir.mk
-include HAL/BLUETOOTH/subdir.mk
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
ITI_Graduation_Project.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ITI_Graduation_Project.elf secondary-outputs

# Tool invocations
ITI_Graduation_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ITI_Graduation_Project.map -mmcu=atmega32 -o "ITI_Graduation_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ITI_Graduation_Project.lss: ITI_Graduation_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ITI_Graduation_Project.elf  >"ITI_Graduation_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ITI_Graduation_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t ITI_Graduation_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ITI_Graduation_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
