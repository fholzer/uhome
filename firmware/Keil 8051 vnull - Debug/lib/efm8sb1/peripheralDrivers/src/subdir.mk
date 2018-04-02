################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/efm8sb1/peripheralDrivers/src/pwr.c \
../lib/efm8sb1/peripheralDrivers/src/smb_0.c 

OBJS += \
./lib/efm8sb1/peripheralDrivers/src/pwr.OBJ \
./lib/efm8sb1/peripheralDrivers/src/smb_0.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8sb1/peripheralDrivers/src/%.OBJ: ../lib/efm8sb1/peripheralDrivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/home/alex/tools/SimplicityStudio_v4/developer/toolchains/keil_8051/9.53/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8sb1/peripheralDrivers/src/pwr.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/peripheral_driver/inc/pwr.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/efm8_config.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/si_toolchain.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdint.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.9/Device/shared/si8051Base/stdbool.h

lib/efm8sb1/peripheralDrivers/src/smb_0.OBJ: /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.8/Device/EFM8SB1/peripheral_driver/inc/smb_0.h /home/alex/SimplicityStudio/v4_workspace/EFM8SB10F8G-A-QFN20/inc/efm8_config.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.8/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h /home/alex/tools/SimplicityStudio_v4/developer/sdks/8051/v4.0.8/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h


