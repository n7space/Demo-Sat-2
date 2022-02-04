project(Samv71RuntimePioHwas VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimePioHwas STATIC)
target_sources(Samv71RuntimePioHwas
    PRIVATE     PioHwas.c
    PUBLIC      PioHwas.h)
target_include_directories(Samv71RuntimePioHwas
    PRIVATE     ..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/../..
                ${CMAKE_CURRENT_SOURCE_DIR}/../../hwas/dataview)
target_link_libraries(Samv71RuntimePioHwas
        PUBLIC      SAMV71::Runtime::Hwas
        PRIVATE     SAMV71::Startup
                    SAMV71::Runtime::RegisterHwas)

add_format_target(Samv71RuntimePioHwas)                

set_target_properties(Samv71RuntimePioHwas PROPERTIES OUTPUT_NAME "PioHwas")
add_library(SAMV71::Runtime::PioHwas ALIAS Samv71RuntimePioHwas)

add_subdirectory(test)