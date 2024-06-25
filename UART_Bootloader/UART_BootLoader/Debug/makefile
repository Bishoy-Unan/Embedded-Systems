################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include 7-APP/BootLoader_USART/subdir.mk
-include 6-Library/subdir.mk
-include 3-SERVICE/02-SYS/subdir.mk
-include 3-SERVICE/01-PARSING/subdir.mk
-include 2-HAL/09-ICU/subdir.mk
-include 2-HAL/08-COM/subdir.mk
-include 2-HAL/07-FAN/subdir.mk
-include 2-HAL/06-SW/subdir.mk
-include 2-HAL/05-USN/subdir.mk
-include 2-HAL/04-TMP/subdir.mk
-include 2-HAL/03-BZR/subdir.mk
-include 2-HAL/02-DCM/subdir.mk
-include 2-HAL/01-LED/subdir.mk
-include 1-MCAL/14-DMA/subdir.mk
-include 1-MCAL/13-ADC/subdir.mk
-include 1-MCAL/12-TIMER/subdir.mk
-include 1-MCAL/11-WWDG/subdir.mk
-include 1-MCAL/10-IWDG/subdir.mk
-include 1-MCAL/09-CRC/subdir.mk
-include 1-MCAL/08-FPEC/subdir.mk
-include 1-MCAL/07-STK/subdir.mk
-include 1-MCAL/06-CAN/subdir.mk
-include 1-MCAL/05-USART/subdir.mk
-include 1-MCAL/04-EXTI/subdir.mk
-include 1-MCAL/03-NVIC/subdir.mk
-include 1-MCAL/02-RCC/subdir.mk
-include 1-MCAL/01-GPIO/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := UART_BootLoader
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
UART_BootLoader.elf \

MAP_FILES += \
UART_BootLoader.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
UART_BootLoader.list \

OBJCOPY_HEX += \
UART_BootLoader.hex \


# All Target
all: main-build

# Main-build Target
main-build: UART_BootLoader.elf secondary-outputs

# Tool invocations
UART_BootLoader.elf UART_BootLoader.map: $(OBJS) $(USER_OBJS) E:\stm_cube\UART_BootLoader\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "UART_BootLoader.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\stm_cube\UART_BootLoader\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="UART_BootLoader.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

UART_BootLoader.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "UART_BootLoader.list"
	@echo 'Finished building: $@'
	@echo ' '

UART_BootLoader.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "UART_BootLoader.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) UART_BootLoader.elf UART_BootLoader.hex UART_BootLoader.list UART_BootLoader.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
