################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-MCAL/02-RCC/RCC_program.c 

OBJS += \
./1-MCAL/02-RCC/RCC_program.o 

C_DEPS += \
./1-MCAL/02-RCC/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
1-MCAL/02-RCC/%.o 1-MCAL/02-RCC/%.su 1-MCAL/02-RCC/%.cyclo: ../1-MCAL/02-RCC/%.c 1-MCAL/02-RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-1-2d-MCAL-2f-02-2d-RCC

clean-1-2d-MCAL-2f-02-2d-RCC:
	-$(RM) ./1-MCAL/02-RCC/RCC_program.cyclo ./1-MCAL/02-RCC/RCC_program.d ./1-MCAL/02-RCC/RCC_program.o ./1-MCAL/02-RCC/RCC_program.su

.PHONY: clean-1-2d-MCAL-2f-02-2d-RCC

