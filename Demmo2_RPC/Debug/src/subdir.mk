################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO_program.c \
../src/NVIC_program.c \
../src/RCC_program.c \
../src/SWITCH_config.c \
../src/SWITCH_program.c \
../src/SYSTick_program.c \
../src/Sched.c \
../src/UART_program.c \
../src/main.c 

OBJS += \
./src/GPIO_program.o \
./src/NVIC_program.o \
./src/RCC_program.o \
./src/SWITCH_config.o \
./src/SWITCH_program.o \
./src/SYSTick_program.o \
./src/Sched.o \
./src/UART_program.o \
./src/main.o 

C_DEPS += \
./src/GPIO_program.d \
./src/NVIC_program.d \
./src/RCC_program.d \
./src/SWITCH_config.d \
./src/SWITCH_program.d \
./src/SYSTick_program.d \
./src/Sched.d \
./src/UART_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


