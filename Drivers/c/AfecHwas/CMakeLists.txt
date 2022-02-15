project(Samv71RuntimeAfecHwas VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeAfecHwas STATIC)
target_sources(Samv71RuntimeAfecHwas
    PRIVATE     AfecHwas.c
    PUBLIC      AfecHwas.h)
target_include_directories(Samv71RuntimeAfecHwas
    PRIVATE     ..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/../..
                ${CMAKE_CURRENT_SOURCE_DIR}/../../hwas/dataview)
target_link_libraries(Samv71RuntimeAfecHwas
        PUBLIC      SAMV71::Runtime::Hwas
        PRIVATE     SAMV71::Startup
                    SAMV71::Runtime::RegisterHwas)

add_format_target(Samv71RuntimeAfecHwas)                

set_target_properties(Samv71RuntimeAfecHwas PROPERTIES OUTPUT_NAME "AfecHwas")
add_library(SAMV71::Runtime::AfecHwas ALIAS Samv71RuntimeAfecHwas)

add_subdirectory(test)
