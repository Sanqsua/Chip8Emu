#ifndef CHIP8_H
#define CHIP8_H

#include "config.h"
#include "chip8registers.h"
#include "chip8memory.h"
struct chip8 {
    struct chip8_memory chip8memory;
    struct chip8_registers chip8registers;
};

#endif