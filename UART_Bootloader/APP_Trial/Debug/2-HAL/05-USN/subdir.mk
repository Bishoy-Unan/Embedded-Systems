################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../2-HAL/05-USN/USN_program.c 

OBJS += \
./2-HAL/05-USN/USN_program.o 

C_DEPS += \
./2-HAL/05-USN/USN_program.d 


# Each subdirectory must supply rules for building sources it contributes
2-HAL/05-USN/%.o 2-HAL/05-USN/%.su 2-HAL/05-USN/%.cyclo: ../2-HAL/05-USN/%.c 2-HAL/05-USN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-2-2d-HAL-2f-05-2d-USN

clean-2-2d-HAL-2f-05-2d-USN:
	-$(RM) ./2-HAL/05-USN/USN_program.cyclo ./2-HAL/05-USN/USN_program.d ./2-HAL/05-USN/USN_program.o ./2-HAL/05-USN/USN_program.su

.PHONY: clean-2-2d-HAL-2f-05-2d-USN

