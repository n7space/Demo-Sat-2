project(DemoSat2TestUtils VERSION 1.0.0 LANGUAGES C)

add_library(DemoSat2TestUtils STATIC)

target_sources(DemoSat2TestUtils
    PRIVATE         Stubs.c)

target_link_libraries(DemoSat2TestUtils
    PRIVATE     SAMV71::FreeRTOS)   

add_format_target(DemoSat2TestUtils)

set_target_properties(DemoSat2TestUtils PROPERTIES OUTPUT_NAME "RuntimeStubs")
add_library(SAMV71::Runtime::Stubs ALIAS DemoSat2TestUtils)
