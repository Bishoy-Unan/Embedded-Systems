################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../3-SERVICE/02-SYS/SYS_program.c 

OBJS += \
./3-SERVICE/02-SYS/SYS_program.o 

C_DEPS += \
./3-SERVICE/02-SYS/SYS_program.d 


# Each subdirectory must supply rules for building sources it contributes
3-SERVICE/02-SYS/%.o 3-SERVICE/02-SYS/%.su 3-SERVICE/02-SYS/%.cyclo: ../3-SERVICE/02-SYS/%.c 3-SERVICE/02-SYS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-3-2d-SERVICE-2f-02-2d-SYS

clean-3-2d-SERVICE-2f-02-2d-SYS:
	-$(RM) ./3-SERVICE/02-SYS/SYS_program.cyclo ./3-SERVICE/02-SYS/SYS_program.d ./3-SERVICE/02-SYS/SYS_program.o ./3-SERVICE/02-SYS/SYS_program.su

.PHONY: clean-3-2d-SERVICE-2f-02-2d-SYS

