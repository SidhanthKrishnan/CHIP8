#!/usr/bin/env bash
set -e
rm -rf build
mkdir build
cd build
# Generate ALL CMake files here
cmake ..
# Build here
make -j$(nproc)
# Run (ROM is inside Source/)
./chip8 10 3 ../Source/tetris.ch8
