#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8memory.h"
int main(int argc, char ** argv)
{

    struct chip8 chip8;
    chip8_memory_set(&chip8.chip8memory,0x400,'z' );
    printf("%c\n", chip8_memory_get(&chip8.chip8memory,0x400));
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