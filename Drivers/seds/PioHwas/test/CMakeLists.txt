project(DemoSat2PioHwasTest VERSION 1.0.0 LANGUAGES C)

adac_compiler(piohwasdriver_ri piohwasdriver)
set(CMAKE_C_COMPILER ${CMAKE_SOURCE_DIR}/adac-hybrid-arm/build/bin/arm-elf-adac)

add_executable(DemoSat2PioHwasTest)

target_sources(DemoSat2PioHwasTest
    PRIVATE     main.c)
    
target_include_directories(DemoSat2PioHwasTest
    PRIVATE     ..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/
                ${CMAKE_SOURCE_DIR}/adac-hybrid-arm/build/lib)

target_link_libraries(DemoSat2PioHwasTest
    PRIVATE     SAMV71::Startup
                SAMV71::Runtime::Init
                ${CMAKE_SOURCE_DIR}/adac-hybrid-arm/build/lib/libgnatcm7.a
                piohwasdriver.o)

set(CMAKE_EXE_LINKER_FLAGS
                " ${CMAKE_EXE_LINKER_FLAGS} \
                -lnosys \
                -nodefaultlibs \
                -L${CMAKE_SOURCE_DIR}/adac-hybrid-arm/build/lib \
                -Xlinker --defsym=HEAP_SIZE=0x8000")

set(CMAKE_C_FLAGS
                "${CMAKE_C_FLAGS} \
                -Wall \
                -Wadac,keep_intermediates \
                -Wgnat,-gnatif \
                -Wgnat,-I${CMAKE_SOURCE_DIR}/adac-hybrid-arm/build/include \
                -Wgnat,-I${CMAKE_SOURCE_DIR}/adac-hybrid-arm/test/utils \
                -Wgnat,--function-sections \
                -g")

target_link_options(DemoSat2PioHwasTest
    PRIVATE     -T${CMAKE_SOURCE_DIR}/TASTE-SAMV71-Runtime/SAMV71-BSP/ld/samv71q21_sram.ld)
    
add_format_target(DemoSat2PioHwasTest)
