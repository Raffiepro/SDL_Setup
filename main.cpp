#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 160*7.5, HEIGHT = 144*7.5;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("WHAT THE SIGMA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL==window)
    {
        std::cout << "THE WINDOW DIDNT FUCKING OPEN >:((((((((((( ERROR: " << SDL_GetError() << '\n';
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_RenderSetScale(renderer, 4, 4);

    SDL_SetRenderDrawColor(renderer, 45, 22, 44, 255);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 151, 117, 166, 255);

    SDL_RenderDrawLine(renderer, 0,0, WIDTH-1,HEIGHT-1);

    SDL_RenderPresent(renderer);

    SDL_Event event;

    while(true)
    {
        if(SDL_PollEvent(&event))
        {
            if(SDL_QUIT==event.type) {break;}
            if(SDL_KEYDOWN==event.type)
            {
                if(SDLK_LEFT==event.key.keysym.sym)
                {std::cout<<"Left";}
                if(SDLK_RIGHT==event.key.keysym.sym)
                {std::cout<<"Right";}
                if(SDLK_UP==event.key.keysym.sym)
                {std::cout<<"Up";}
                if(SDLK_DOWN==event.key.keysym.sym)
                {std::cout<<"Down";}
            }
            if(SDL_KEYUP==event.type)
            {
                std::cout << "Keyup\n";
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}