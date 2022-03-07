project(UartHwasTest VERSION 1.0.0 LANGUAGES C CXX)

add_executable(UartHwasTest)
target_sources(UartHwasTest
    PRIVATE     main.cpp)
target_include_directories(UartHwasTest
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/../..
                ${CMAKE_CURRENT_SOURCE_DIR}/../../../../
                ${CMAKE_SOURCE_DIR}/TASTE-SAMV71-Runtime/src
                ${CMAKE_SOURCE_DIR}/cpputest/include )
target_link_libraries(UartHwasTest
    PRIVATE     SAMV71::Runtime::UartHwas
                CppUTestExt
                CppUTest
                m
                stdc++
                c
                gcc
                SAMV71::FreeRTOS
                SAMV71::Stubs
                SAMV71::Runtime::Stubs
                SAMV71::Runtime::Init)
set(CMAKE_EXE_LINKER_FLAGS
                " ${CMAKE_EXE_LINKER_FLAGS} \
                -lnosys \
                -nodefaultlibs \
                -Xlinker --defsym=HEAP_SIZE=0x8000")
set(CMAKE_CXX_FLAGS
                "${CMAKE_CXX_FLAGS} \
                -DCPPUTEST_USE_MEM_LEAK_DETECTION=0")

target_link_options(UartHwasTest
    PRIVATE     -T${CMAKE_SOURCE_DIR}/TASTE-SAMV71-Runtime/SAMV71-BSP/ld/samv71q21_sram.ld)

add_format_target(UartHwasTest)
