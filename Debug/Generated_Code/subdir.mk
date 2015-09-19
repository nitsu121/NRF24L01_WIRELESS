################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/SERIAL1.c \
../Generated_Code/clockMan1.c \
../Generated_Code/dspiCom1.c \
../Generated_Code/flexTimer1.c \
../Generated_Code/gpio1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_mux.c \
../Generated_Code/pit100us.c \
../Generated_Code/pitTimer1.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/SERIAL1.o \
./Generated_Code/clockMan1.o \
./Generated_Code/dspiCom1.o \
./Generated_Code/flexTimer1.o \
./Generated_Code/gpio1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_mux.o \
./Generated_Code/pit100us.o \
./Generated_Code/pitTimer1.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/SERIAL1.d \
./Generated_Code/clockMan1.d \
./Generated_Code/dspiCom1.d \
./Generated_Code/flexTimer1.d \
./Generated_Code/gpio1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_mux.d \
./Generated_Code/pit100us.d \
./Generated_Code/pitTimer1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MK64FN1M0VLL12" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/hal/inc" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/hal/src/sim/MK64F12" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/system/src/clock/MK64F12" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/system/inc" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/osa/inc" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/CMSIS/Include" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/devices" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/devices/MK64F12/include" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/devices/MK64F12/startup" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/Generated_Code/SDK/platform/devices/MK64F12/startup" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/Sources" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/Generated_Code" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


