################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7-APP/BootLoader_USART/main.c 

OBJS += \
./7-APP/BootLoader_USART/main.o 

C_DEPS += \
./7-APP/BootLoader_USART/main.d 


# Each subdirectory must supply rules for building sources it contributes
7-APP/BootLoader_USART/%.o 7-APP/BootLoader_USART/%.su 7-APP/BootLoader_USART/%.cyclo: ../7-APP/BootLoader_USART/%.c 7-APP/BootLoader_USART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-7-2d-APP-2f-BootLoader_USART

clean-7-2d-APP-2f-BootLoader_USART:
	-$(RM) ./7-APP/BootLoader_USART/main.cyclo ./7-APP/BootLoader_USART/main.d ./7-APP/BootLoader_USART/main.o ./7-APP/BootLoader_USART/main.su

.PHONY: clean-7-2d-APP-2f-BootLoader_USART

