cmake_minimum_required(VERSION 3.14)
project(chip8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2 installed via apt
find_package(SDL2 REQUIRED)

# Create executable
add_executable(
    chip8
    Source/Chip8.cpp
    Source/Main.cpp
    Source/Platform.cpp
)

# Include SDL2 headers
target_include_directories(chip8 PRIVATE ${SDL2_INCLUDE_DIRS})

# Compiler warnings
target_compile_options(chip8 PRIVATE -Wall)

# Link SDL2 ONLY
target_link_libraries(chip8 PRIVATE ${SDL2_LIBRARIES})
