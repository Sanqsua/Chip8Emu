#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8memory.h"

#include "chip8stack.h"
int main(int argc, char ** argv)
{

    struct chip8 chip8;
    chip8.chip8registers.SP = 0;
    chip8_stack_push(&chip8,0xff);
    printf("Stackpointer index: %d\n",chip8.chip8registers.SP);
    printf("Stackpointer: %d\n",chip8.chip8stack.stack[chip8.chip8registers.SP-1]);

    unsigned char popvalue = chip8_stack_pop(&chip8);
    printf("Stackpointer index: %d\n", chip8.chip8registers.SP);
    printf("Stackpointer value: %d\n", popvalue);
 
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(
        CONFIG_EMULATOR_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CONFIG_CHIP8_WIDTH * CONFIG_CHIP8_WINDOW_MULTIPLIER, 
        CONFIG_CHIP8_HEIGHT * CONFIG_CHIP8_WINDOW_MULTIPLIER,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    for(;;)
    {
        SDL_Event event;
        //Draw a rectangle
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                goto Exit;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0,0,0,0);
        SDL_RenderClear(renderer);
        
        drawRect(renderer);
        SDL_RenderPresent(renderer);
    }

Exit:
    SDL_DestroyWindow(window);
    return 0;
}

void drawRect(SDL_Renderer *renderer)
{
    SDL_Rect r;
        SDL_SetRenderDrawColor(renderer, 255,255,255,0);
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 50;
        SDL_RenderFillRect(renderer, &r);
}