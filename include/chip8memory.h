#ifndef CHIP8MEMORY_H
#define CHIP8MEMORY_H
#include "config.h"

struct chip8_memory {
    unsigned char memory[CONFIG_CHIP8_MEMORY_SIZE];
};
//getters and setters for the memory
// pass a pointer to the memory to get and set the value 
void chip8_memory_set(struct chip8_memory* memory,int index, unsigned char value);
unsigned char chip8_memory_get(struct chip8_memory* memory,int index);
#endif // chip8memory.h