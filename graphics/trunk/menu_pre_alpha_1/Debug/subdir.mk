################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Funcs.cpp \
../MainMenu2.cpp \
../OkCancel.cpp \
../main.cpp 

OBJS += \
./Funcs.o \
./MainMenu2.o \
./OkCancel.o \
./main.o 

CPP_DEPS += \
./Funcs.d \
./MainMenu2.d \
./OkCancel.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


