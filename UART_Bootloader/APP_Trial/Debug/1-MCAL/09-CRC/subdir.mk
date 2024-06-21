################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-MCAL/09-CRC/CRC_program.c 

OBJS += \
./1-MCAL/09-CRC/CRC_program.o 

C_DEPS += \
./1-MCAL/09-CRC/CRC_program.d 


# Each subdirectory must supply rules for building sources it contributes
1-MCAL/09-CRC/%.o 1-MCAL/09-CRC/%.su 1-MCAL/09-CRC/%.cyclo: ../1-MCAL/09-CRC/%.c 1-MCAL/09-CRC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-1-2d-MCAL-2f-09-2d-CRC

clean-1-2d-MCAL-2f-09-2d-CRC:
	-$(RM) ./1-MCAL/09-CRC/CRC_program.cyclo ./1-MCAL/09-CRC/CRC_program.d ./1-MCAL/09-CRC/CRC_program.o ./1-MCAL/09-CRC/CRC_program.su

.PHONY: clean-1-2d-MCAL-2f-09-2d-CRC

