cmake_minimum_required(VERSION 3.13)

#include the cmake build functions from pico SDK
include(pico_sdk_import.cmake)

#project name and code here
project(BLINKRTT C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


#bring in this function to add cmake Pico SDK functionality to build
pico_sdk_init()

#list out files used
add_executable(${PROJECT_NAME}
	blinkcl.c add.c SEGGER_RTT.c SEGGER_RTT_printf.c
	)

#create extra uf2 etc files
pico_add_extra_outputs(${PROJECT_NAME})

#linker needs to use these libraries
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
)

#uart fart
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
