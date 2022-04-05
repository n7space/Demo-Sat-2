cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/TASTE-SAMV71-Runtime/toolchains/samv71.cmake)

project(DemoSat2 VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(MessageColors)
include(LoggingHelper)
include(ClangFormat)

include(Adac)

add_library(common_build_options INTERFACE)
include(CommonBuildOptions)
include(Sanitizers)

add_library(bsp_build_options INTERFACE)
target_compile_definitions(bsp_build_options
    INTERFACE   USE_USB_USART_IO)

add_subdirectory(TASTE-SAMV71-Runtime/SAMV71-BSP)
add_subdirectory(TASTE-SAMV71-Runtime/FreeRTOS)
add_subdirectory(TASTE-SAMV71-Runtime/src/hwas)
add_subdirectory(TASTE-SAMV71-Runtime/src/Init)
add_subdirectory(TASTE-SAMV71-Runtime/src/Hal)
add_subdirectory(TASTE-SAMV71-Runtime/src/Xdmac)

add_subdirectory(Drivers)
add_subdirectory(TestUtils)

# Build cpputest
option(TESTS OFF)
option(TESTS_BUILD_DISCOVER OFF)
option(MEMORY_LEAK_DETECTION OFF)
set(CPP_PLATFORM armcc)

add_subdirectory(cpputest)
