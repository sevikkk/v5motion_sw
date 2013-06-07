################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dispatch.c \
../src/echo.c \
../src/helloworld.c \
../src/leds.c \
../src/network.c \
../src/platform.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/dispatch.o \
./src/echo.o \
./src/helloworld.o \
./src/leds.o \
./src/network.o \
./src/platform.o 

C_DEPS += \
./src/dispatch.d \
./src/echo.d \
./src/helloworld.d \
./src/leds.d \
./src/network.d \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -Wl,--no-relax -D __XMK__ -I../../eth_bsp/microblaze_0/include -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v8.40.b -mno-xl-soft-mul -mxl-multiply-high -mhard-float -mxl-float-convert -mxl-float-sqrt -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


