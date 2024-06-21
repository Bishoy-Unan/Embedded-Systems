################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../2-HAL/08-COM/COM_program.c 

OBJS += \
./2-HAL/08-COM/COM_program.o 

C_DEPS += \
./2-HAL/08-COM/COM_program.d 


# Each subdirectory must supply rules for building sources it contributes
2-HAL/08-COM/%.o 2-HAL/08-COM/%.su 2-HAL/08-COM/%.cyclo: ../2-HAL/08-COM/%.c 2-HAL/08-COM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-2-2d-HAL-2f-08-2d-COM

clean-2-2d-HAL-2f-08-2d-COM:
	-$(RM) ./2-HAL/08-COM/COM_program.cyclo ./2-HAL/08-COM/COM_program.d ./2-HAL/08-COM/COM_program.o ./2-HAL/08-COM/COM_program.su

.PHONY: clean-2-2d-HAL-2f-08-2d-COM

