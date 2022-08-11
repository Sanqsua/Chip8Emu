#include "chip8stack.h"
#include "chip8.h"
#include <assert.h>
#include "config.h"
static void chip8_stack_in_bounds(struct chip8* chip8)
{
    /*unsigned short-> no need to check for stackpointer > 0 */
    assert(CONFIG_CHIP8_STACK_DEPTH > chip8->chip8registers.SP );
}

void chip8_stack_push(struct chip8 *chip8, unsigned short value)
{
    /*
        first push the valu then increment stackpointer
    */
    chip8_stack_in_bounds(chip8);
    chip8->chip8stack.stack[chip8->chip8registers.SP] = value;
    chip8->chip8registers.SP++;
}

/*
    First decrement the Stackpointer and then return value
*/
unsigned short chip8_stack_pop(struct chip8* chip8)
{
    
    chip8->chip8registers.SP--; 
    chip8_stack_in_bounds(chip8);
    unsigned short result = chip8->chip8stack.stack[chip8->chip8registers.SP];
    
    return result;
}
