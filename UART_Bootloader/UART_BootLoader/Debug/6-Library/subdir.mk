################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../6-Library/MAPP_program.c \
../6-Library/STRING_COMPARE.c 

OBJS += \
./6-Library/MAPP_program.o \
./6-Library/STRING_COMPARE.o 

C_DEPS += \
./6-Library/MAPP_program.d \
./6-Library/STRING_COMPARE.d 


# Each subdirectory must supply rules for building sources it contributes
6-Library/%.o 6-Library/%.su 6-Library/%.cyclo: ../6-Library/%.c 6-Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-6-2d-Library

clean-6-2d-Library:
	-$(RM) ./6-Library/MAPP_program.cyclo ./6-Library/MAPP_program.d ./6-Library/MAPP_program.o ./6-Library/MAPP_program.su ./6-Library/STRING_COMPARE.cyclo ./6-Library/STRING_COMPARE.d ./6-Library/STRING_COMPARE.o ./6-Library/STRING_COMPARE.su

.PHONY: clean-6-2d-Library

