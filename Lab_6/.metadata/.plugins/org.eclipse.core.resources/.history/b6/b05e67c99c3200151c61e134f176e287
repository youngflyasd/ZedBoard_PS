################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
lab_6.elf.size \


# All Target
all: lab_6.elf secondary-outputs

# Tool invocations
lab_6.elf: $(OBJS)  $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: ARM Linux gcc linker
	arm-xilinx-linux-gnueabi-gcc  -o"lab_6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

lab_6.elf.size: lab_6.elf
	@echo Invoking: ARM Linux Print Size
	arm-xilinx-linux-gnueabi-size lab_6.elf  |tee "lab_6.elf.size"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(S_UPPER_DEPS) lab_6.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
