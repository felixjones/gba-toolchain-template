cmake_minimum_required(VERSION 3.18)

project(gba-template)

if(NOT CMAKE_SYSTEM_NAME STREQUAL AdvancedGameBoy)
    message(FATAL_ERROR "System is not AdvancedGameBoy (got ${CMAKE_SYSTEM_NAME}). Did you remember to download gba-toolchain?")
endif()

find_package(librom REQUIRED) # GBA ROM runtime library
find_package(tonclib REQUIRED) # Tonc C development library
find_package(grit REQUIRED) # grit image library

# Add tilemap asset
add_grit_tilemap(tilemap_assets C brin-full.png)

# Add executable
add_executable(brin_demo main.c)

target_compile_options(brin_demo PRIVATE -mthumb -Wall -fno-strict-aliasing)

target_link_libraries(brin_demo PRIVATE librom tonclib tilemap_assets)

# install .gba ROM (also runs gbafix)
install_rom(brin_demo)
