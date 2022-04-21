cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

add_executable(LinuxPartition)
target_sources(LinuxPartition
  PRIVATE   main.cpp
            PacketSender.cpp
  PUBLIC    PacketSender.h)

target_include_directories(LinuxPartition
  PRIVATE   ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/TASTE-Linux-Drivers/src
            ${CMAKE_SOURCE_DIR}/TASTE-Linux-Drivers/src/RuntimeMocks
            ${CMAKE_SOURCE_DIR}/TASTE-Linux-Drivers/TASTE-Linux-Runtime/src)

target_link_libraries(LinuxPartition
  PRIVATE   common_build_options
            TASTE::Packetizer
            TASTE::LinuxSerialCcsds
            LinuxRuntime
            pthread)

add_format_target(LinuxPartition)

