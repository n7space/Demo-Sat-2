cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(DemoSat2 VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../cmake)

include(MessageColors)
include(LoggingHelper)
include(ClangFormat)

add_library(common_build_options INTERFACE)
include(CommonBuildOptions)
include(Sanitizers)

add_subdirectory(TASTE-Linux-Drivers/src/linux_serial_ccsds)
add_subdirectory(TASTE-Linux-Drivers/TASTE-Linux-Runtime/src)
add_subdirectory(TASTE-Linux-Drivers/TASTE-Runtime-Common/src/Escaper)
add_subdirectory(TASTE-Linux-Drivers/TASTE-Runtime-Common/src/Broker)
add_subdirectory(TASTE-Linux-Drivers/TASTE-Runtime-Common/src/Packetizer)
add_subdirectory(TASTE-Linux-Drivers/TASTE-Runtime-Common/src/RuntimeMocks)

add_subdirectory(UartHwas/example/linuxPartition)
