################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7-APP/APP\ ECU_1/main.c 

OBJS += \
./7-APP/APP\ ECU_1/main.o 

C_DEPS += \
./7-APP/APP\ ECU_1/main.d 


# Each subdirectory must supply rules for building sources it contributes
7-APP/APP\ ECU_1/main.o: ../7-APP/APP\ ECU_1/main.c 7-APP/APP\ ECU_1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"7-APP/APP ECU_1/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-7-2d-APP-2f-APP-20-ECU_1

clean-7-2d-APP-2f-APP-20-ECU_1:
	-$(RM) ./7-APP/APP\ ECU_1/main.cyclo ./7-APP/APP\ ECU_1/main.d ./7-APP/APP\ ECU_1/main.o ./7-APP/APP\ ECU_1/main.su

.PHONY: clean-7-2d-APP-2f-APP-20-ECU_1

