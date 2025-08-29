################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
Pwm_example_S32K344_2.siz \


# All Target
all: Pwm_example_S32K344_2.elf secondary-outputs

# Tool invocations
Pwm_example_S32K344_2.elf: $(OBJS) C:/Users/b/workspaceS32DS.3.5/Pwm_example_S32K344_2/Project_Settings/Linker_Files/linker_flash_s32k344.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "Pwm_example_S32K344_2.elf" "@Pwm_example_S32K344_2.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Pwm_example_S32K344_2.siz: Pwm_example_S32K344_2.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley Pwm_example_S32K344_2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
