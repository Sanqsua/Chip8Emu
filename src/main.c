#include <stdio.h>
#include "SDL2/SDL.h"
int main(int argc, char ** argv)
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow(
        "CHIP8 WINDOW",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 320, SDL_WINDOW_SHOWN
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
        SDL_Rect r;
        SDL_SetRenderDrawColor(renderer, 255,255,255,0);
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 40;
        SDL_RenderFillRect(renderer, &r);
        SDL_RenderPresent(renderer);
    }

Exit:
    SDL_DestroyWindow(window);
    return 0;
}