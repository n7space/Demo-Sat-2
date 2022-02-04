project(Samv71RuntimeRegisterHwas VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeRegisterHwas)
target_sources(Samv71RuntimeRegisterHwas
    PRIVATE     RegisterHwas.c
    PUBLIC      RegisterHwas.h)
target_include_directories(Samv71RuntimeRegisterHwas
    PRIVATE     ..
    PUBLIC      ${CMAKE_SOURCE_DIR}/TASTE-SAMV71-Runtime/src/)
target_link_libraries(Samv71RuntimeRegisterHwas
    PUBLIC      SAMV71::Runtime::Hwas
    PRIVATE     SAMV71::Startup)

add_format_target(Samv71RuntimeRegisterHwas)

set_target_properties(Samv71RuntimeRegisterHwas PROPERTIES OUTPUT_NAME "RegisterHwas")
add_library(SAMV71::Runtime::RegisterHwas ALIAS Samv71RuntimeRegisterHwas)
