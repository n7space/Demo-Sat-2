project(Samv71RuntimeUartHwas VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeUartHwas STATIC)
target_sources(Samv71RuntimeUartHwas
    PRIVATE     UartHwas.c
    PUBLIC      UartHwas.h)
target_include_directories(Samv71RuntimeUartHwas
    PRIVATE     ..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/../..
                ${CMAKE_CURRENT_SOURCE_DIR}/../../hwas/dataview)
target_link_libraries(Samv71RuntimeUartHwas
        PUBLIC      SAMV71::Runtime::Hwas
        PRIVATE     SAMV71::Startup
                    SAMV71::Runtime::RegisterHwas)

add_format_target(Samv71RuntimeUartHwas)                

set_target_properties(Samv71RuntimeUartHwas PROPERTIES OUTPUT_NAME "UartHwas")
add_library(SAMV71::Runtime::UartHwas ALIAS Samv71RuntimeUartHwas)

add_subdirectory(test)
