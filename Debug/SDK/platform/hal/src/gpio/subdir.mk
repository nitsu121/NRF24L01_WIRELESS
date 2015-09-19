################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/hal/src/gpio/fsl_gpio_hal.c 

OBJS += \
./SDK/platform/hal/src/gpio/fsl_gpio_hal.o 

C_DEPS += \
./SDK/platform/hal/src/gpio/fsl_gpio_hal.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/hal/src/gpio/%.o: ../SDK/platform/hal/src/gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MK64FN1M0VLL12" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/hal/inc" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/hal/src/sim/MK64F12" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/system/src/clock/MK64F12" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/system/inc" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/osa/inc" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/CMSIS/Include" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/devices" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/devices/MK64F12/include" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/devices/MK64F12/startup" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/Generated_Code/SDK/platform/devices/MK64F12/startup" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/Sources" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/Generated_Code" -I"C:/freescale/workspace.kds/TestKSDKProjectSerial/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


