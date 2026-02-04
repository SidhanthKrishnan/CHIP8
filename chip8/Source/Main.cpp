#include "Chip8.hpp"
#include "Platform.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
        exit(EXIT_FAILURE);
    }

    int windowScale    = stoi(argv[1]);
    int instructionGap = stoi(argv[2]);
    string romPath     = argv[3];

    Platform window(
        "CHIP-8 Emulator",
        VIDEO_WIDTH  * windowScale,
        VIDEO_HEIGHT * windowScale,
        VIDEO_WIDTH,
        VIDEO_HEIGHT
    );

    Chip8 emulator;
    emulator.LoadROM(romPath);

    int frameStride = sizeof(emulator.video[0]) * VIDEO_WIDTH;

    auto lastTick = high_resolution_clock::now();
    bool shouldExit = false;

    while (!shouldExit)
    {
        shouldExit = window.ProcessInput(emulator.keypad);

        auto now = high_resolution_clock::now();
        float elapsedMs =
            duration<float, milliseconds::period>(now - lastTick).count();

        if (elapsedMs > instructionGap)
        {
            lastTick = now;

            emulator.Cycle();
            window.Update(emulator.video, frameStride);
        }
    }

    return 0;
}
