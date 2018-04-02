################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EFM8SB10F8G-A-QFN20_main.c \
../src/InitDevice.c \
../src/Interrupts.c \
../src/SmaRTClock.c \
../src/peripherals.c \
../src/power.c 

OBJS += \
./src/EFM8SB10F8G-A-QFN20_main.OBJ \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SmaRTClock.OBJ \
./src/peripherals.OBJ \
./src/power.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/home/alex/tools/SimplicityStudio_v4/developer/toolchains/keil_8051/9.53/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/EFM8SB10F8G-A-QFN20_main.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/InitDevice.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/peripherals.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/peripheral_driver/inc/smb_0.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/power.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/SmaRTClock.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/efm8_config.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h

src/InitDevice.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/InitDevice.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h

src/SmaRTClock.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h

src/peripherals.OBJ: /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/peripherals.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/peripheral_driver/inc/smb_0.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/efm8_config.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h

src/power.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h


