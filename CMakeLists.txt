cmake_minimum_required(VERSION 3.0)

SET(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

set(CMAKE_C_FLAGS " -DF_CPU=16000000UL -mmcu=atmega328p " )

project(AvrKeyboard)
add_executable(${PROJECT_NAME} "main.c" "scheduler.c" "scheduler.h" "usart.c" "usart.h")
