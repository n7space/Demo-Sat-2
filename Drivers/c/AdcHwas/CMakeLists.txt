project(Samv71RuntimeAdcHwas VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeAdcHwas STATIC)
target_sources(Samv71RuntimeAdcHwas
    PRIVATE     AdcHwas.c
    PUBLIC      AdcHwas.h)
target_include_directories(Samv71RuntimeAdcHwas
    PRIVATE     ..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/../..
                ${CMAKE_CURRENT_SOURCE_DIR}/../../hwas/dataview)
target_link_libraries(Samv71RuntimeAdcHwas
        PUBLIC      SAMV71::Runtime::Hwas
        PRIVATE     SAMV71::Startup
                    SAMV71::Runtime::RegisterHwas)

add_format_target(Samv71RuntimeAdcHwas)                

set_target_properties(Samv71RuntimeAdcHwas PROPERTIES OUTPUT_NAME "PioHwas")
add_library(SAMV71::Runtime::PioHwas ALIAS Samv71RuntimeAdcHwas)

add_subdirectory(test)
