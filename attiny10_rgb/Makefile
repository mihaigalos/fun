################################################################################
# Automatically-generated file. Do not edit!
################################################################################

PROJECT = attiny10_rgb
MICROCONTROLLER = attiny10
SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
$(PROJECT).cpp \
../Drivers/AVR/SoftwareUart/SoftwareUart.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
$(PROJECT).o \
SoftwareUart.o

OBJS_AS_ARGS +=  \
$(PROJECT).o \
SoftwareUart.o

C_DEPS +=  \
$(PROJECT).d \
SoftwareUart.d

C_DEPS_AS_ARGS +=  \
$(PROJECT).d \
SoftwareUart.d

OUTPUT_FILE_PATH +=$(PROJECT).elf

OUTPUT_FILE_PATH_AS_ARGS +=$(PROJECT).elf

ADDITIONAL_DEPENDENCIES:=



LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


ifndef Tiny10DescriptionFiles
$(error Tiny10DescriptionFiles Environment Variable is not set. Please set it to i.e. <Program Files>\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.1.102)
endif

# AVR32/GNU C Compiler


SoftwareUart.o: ../Drivers/AVR/SoftwareUart/SoftwareUart.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -I"%TinyDescriptionFiles%\include" -I"../.."  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=$(MICROCONTROLLER) -B "%TinyDescriptionFiles%\gcc\dev\$(MICROCONTROLLER)" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	@echo.

./%.o: ./%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -I"%TinyDescriptionFiles%\include" -I"../.."  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=$(MICROCONTROLLER) -B "%TinyDescriptionFiles%\gcc\dev\$(MICROCONTROLLER)" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	@echo.
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 



# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.9.2
	$(QUOTE)avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="$(PROJECT).map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=$(MICROCONTROLLER) -B "%TinyDescriptionFiles%\gcc\dev\$(MICROCONTROLLER)"  
	@echo Finished building target: $@
	@echo.
	"avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "$(PROJECT).elf" "$(PROJECT).hex"
	"avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "$(PROJECT).elf" "$(PROJECT).eep" || exit 0
	"avr-objdump.exe" -h -S "$(PROJECT).elf" > "$(PROJECT).lss"
	"avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "$(PROJECT).elf" "$(PROJECT).srec"
	"avr-size.exe" "$(PROJECT).elf"
	


# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "$(PROJECT).elf" "$(PROJECT).a" "$(PROJECT).hex" "$(PROJECT).lss" "$(PROJECT).eep" "$(PROJECT).map" "$(PROJECT).srec" "$(PROJECT).usersignatures"
	