project(Samv71RuntimeLidarHwas VERSION 1.0.0 LANGUAGES C)

add_executable(Samv71RuntimeLidarHwas main.c)

target_include_directories(Samv71RuntimeLidarHwas
    PRIVATE     ..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/../
                ${CMAKE_CURRENT_SOURCE_DIR}/../
                ${CMAKE_CURRENT_SOURCE_DIR}/../TASTE-SAMV71-Runtime/src
                ${CMAKE_CURRENT_SOURCE_DIR}/../TASTE-SAMV71-Runtime/src/hwas/dataview
                ${CMAKE_CURRENT_SOURCE_DIR}/../TASTE-SAMV71-Runtime/SAMV71-BSP/src)
target_link_libraries(Samv71RuntimeLidarHwas
    PRIVATE     SAMV71::Runtime::Init
                SAMV71::Runtime::Hal
                SAMV71::FreeRTOS 
                SAMV71::Runtime::Hwas
                SAMV71::Startup
                SAMV71::Runtime::RegisterHwas
                SAMV71::Runtime::PioHwas
                SAMV71::Runtime::UartHwas)

target_link_options(Samv71RuntimeLidarHwas
    PRIVATE     -T${CMAKE_CURRENT_SOURCE_DIR}/../TASTE-SAMV71-Runtime/SAMV71-BSP/ld/samv71q21_sram.ld)

add_format_target(Samv71RuntimeLidarHwas)                

set_target_properties(Samv71RuntimeLidarHwas PROPERTIES OUTPUT_NAME "LidarExample")
