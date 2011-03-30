################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./ChangeEngine.cpp \
./GameInput.cpp \
./GameNetwork.cpp \
./GameObject.cpp \
./GameSound.cpp \
./GameWindow.cpp \
./LogicalGameObject.cpp \
./VisibleGameObject.cpp 

OBJS += \
./ChangeEngine.o \
./GameInput.o \
./GameNetwork.o \
./GameObject.o \
./GameSound.o \
./GameWindow.o \
./LogicalGameObject.o \
./VisibleGameObject.o 

CPP_DEPS += \
./ChangeEngine.d \
./GameInput.d \
./GameNetwork.d \
./GameObject.d \
./GameSound.d \
./GameWindow.d \
./LogicalGameObject.d \
./VisibleGameObject.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ./%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


