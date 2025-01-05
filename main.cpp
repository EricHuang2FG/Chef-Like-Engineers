#ifdef WINDOWS
  #define SDL_MAIN_HANDLED
  #include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_ttf.h>
  #include <SDL_mixer.h>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
  #include <SDL2/SDL_ttf.h>
  #include <SDL2/SDL_mixer.h>
#endif 

#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

void draw(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255); // background
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        cout << "We're cooked (can't even initialize the god damn library)" << endl;
    }
	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "We're cooked 1.1 (Image initialization failed): " << IMG_GetError() << endl;
	if (!(TTF_Init()))
		cout << "We're cooked 1.2 (TTF initialization failed): " << TTF_GetError() << endl;

    SDL_Window* window = SDL_CreateWindow("Chef Like Engineers (Mech + EngSci 2T8)",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        cout << "We're cooked 2.0 (can't load window): " << SDL_GetError() << endl;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        cout << "We're cooked 3.0 (can't load the renderer)" << SDL_GetError() << endl;
    }

    bool run = true;
    SDL_Event event;

    while (run) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }
        }
        draw(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
