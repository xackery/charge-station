cmake_minimum_required(VERSION 3.13)

include(deps/pico-sdk/pico_sdk_init.cmake)
# TODO include(pico_extras_import_optional.cmake)

project(src C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

pico_sdk_init()

add_executable(src
    main.c
)

target_link_libraries(src pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(src 1)
pico_enable_stdio_uart(src 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(src)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()