
#ifndef CHIP8REGISTERS_H
#define CHIP8REGISTERS_H
#include "config.h"
/* source http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#2.5
    registers are only storage regions in the processor that are outside of the main memory
    similar to cache

1.Chip-8 has 16 general purpose 8-bit registers, usually referred to as Vx, where x is a hexadecimal digit (0 through F).

2.There is also a 16-bit register called I. This register is generally used to store memory addresses, so only the lowest (rightmost) 12 bits are usually used.

x.The VF register should not be used by any program, as it is used as a flag by some instructions. See section 3.0, Instructions for details.
(VF is not needed  )

3&4.Chip-8 also has two special purpose 8-bit registers, for the delay and sound timers. When these registers are non-zero, they are automatically decremented at a rate of 60Hz.
See the section 2.5, Timers & Sound, for more information on these.

5&6.There are also some "pseudo-registers" which are not accessable from Chip-8 programs. The program counter (PC) should be 16-bit, 
and is used to store the currently executing address. 
The stack pointer (SP) can be 8-bit, it is used to point to the topmost level of the stack.
The stack is an array of 16 16-bit values, used to store the address that the interpreter shoud return to when finished with a subroutine. 
Chip-8 allows for up to 16 levels of nested subroutines.

*/
/*
registers to implement: Vx,I soundtimer and delaytimer, pseudo_registers 
    1  Vx ->is general purpose-> has 16x8bit (chars)   
    2 I ->is used to store memory addresses -> has 16 bit (short)
    3  timer_delay -> 8bit (char)
    4 timer_delay -> 8bit (char)
    5 pseudo_registers ->   program counter (PC)-> 16bit (short) 
                            stack counter (SP) 8bit (char) 
*/
struct chip8_registers{
    unsigned char Vx[CONFIG_CHIP8_TOTAL_DATA_REGISTERS]; // 16 char (8 bit) registers
    unsigned short I; //short is 16 bit or 2 byte
    unsigned char timer_delay;
    unsigned char timer_sound;
    unsigned short PC;
    unsigned char SP; 
};

#endif