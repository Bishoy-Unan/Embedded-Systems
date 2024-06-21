################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-MCAL/07-STK/STK_program.c 

OBJS += \
./1-MCAL/07-STK/STK_program.o 

C_DEPS += \
./1-MCAL/07-STK/STK_program.d 


# Each subdirectory must supply rules for building sources it contributes
1-MCAL/07-STK/%.o 1-MCAL/07-STK/%.su 1-MCAL/07-STK/%.cyclo: ../1-MCAL/07-STK/%.c 1-MCAL/07-STK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-1-2d-MCAL-2f-07-2d-STK

clean-1-2d-MCAL-2f-07-2d-STK:
	-$(RM) ./1-MCAL/07-STK/STK_program.cyclo ./1-MCAL/07-STK/STK_program.d ./1-MCAL/07-STK/STK_program.o ./1-MCAL/07-STK/STK_program.su

.PHONY: clean-1-2d-MCAL-2f-07-2d-STK

