# 🕹️ CHIP-8 Emulator (C++ / SDL2)

A modern CHIP-8 emulator written in C++, designed to explore low-level computer architecture concepts through hands-on implementation. This project emphasizes correctness, timing accuracy, and clean software design using modern C++ practices.

---

## 👤 About the Author

Hi, I’m **Sidhanth Krishnan**, an undergraduate student with interests in computer architecture, systems programming, and modern C++.

This project was developed alongside my coursework in **Microprocessors (MUP)** and **Advanced C++ Programming**, with the goal of translating theoretical hardware concepts—such as instruction cycles, memory maps, and timers—into a working software system.

---

## 🧠 Project Overview

CHIP-8 is a simple interpreted virtual machine originally developed in the 1970s. Despite its simplicity, it provides an excellent platform for understanding:

- CPU fetch–decode–execute cycles  
- Instruction decoding and execution  
- Memory and stack management  
- Timing-sensitive systems  
- Input and graphics abstraction  

This emulator recreates those behaviors using modern C++ and SDL2 for platform-independent graphics and input.

---

## 🔑 Key Technical Features

### CPU & Architecture
- Full Fetch–Decode–Execute pipeline
- 35 CHIP-8 opcodes implemented
- 4KB memory space (0x000–0xFFF)
- 16 general-purpose registers (V0–VF)
- Index register, program counter, stack pointer
- 16-level call stack

### Software Design
- `Chip8` class encapsulates CPU state and opcode logic
- `Platform` layer abstracts SDL2-based rendering and keyboard input
- Clear separation between emulation logic and platform-specific code

### Timing & Synchronization
- Uses `std::chrono` for precise timing
- Configurable instruction execution rate (~500 Hz)
- Delay and sound timers synchronized at 60 Hz
- Rendering decoupled from CPU execution

---

## 📚 References & Design Decisions

This project was developed with reference to **Austin Morlan’s blog series on building a CHIP-8 emulator**, which provides a clear conceptual introduction to emulator structure and opcode handling. You can use this resource too if you are starting out with emulation.

### Design Modifications
- Certain fixed-size arrays used in reference implementations were replaced with **`std::map`** to reduce unnecessary memory usage and improve semantic clarity where sparse access patterns are present.
- Emulator components were reorganized to improve modularity and maintainability.
- Timing logic was explicitly controlled using `std::chrono` for more predictable behavior.

---

## 🕹️ Tested ROMs

- Tetris — sprite stacking and memory persistence  
- Pong — real-time input handling and collision detection  
- Space Invaders — multiple moving entities and rapid screen updates  

---

## 🚀 Build & Run
### Run the Emulator
```bash
chmod +x script.sh
./script.sh
