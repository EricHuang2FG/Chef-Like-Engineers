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

#include "GameManager.h"
#include "Game Objects/Player.h"
#include "Constants.h"
#include <iostream>
#include "States/TestStateA.h"
#include "States/TestStateB.h"
using namespace std;

const SDL_Rect backgroundRect =  { 0, 0, 1200, 800};
SDL_Texture* testBackground;

void draw(SDL_Renderer* renderer, Player& player) {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255); // background
    
    SDL_RenderCopyEx(renderer, testBackground, NULL, &backgroundRect, 0, NULL, SDL_FLIP_NONE);
    player.draw();
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        cout << "We're cooked (can't even initialize the god damn library)" << endl;
    }
	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "We're cooked 1.1 (Image initialization failed): " << IMG_GetError() << endl;
	if (TTF_Init() == -1)
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

    testBackground = IMG_LoadTexture(renderer, ("./Assets/Backgrounds/pit.png"));

    bool run = true;
    SDL_Event event;

    // GameManager gameManager;
    // TestStateA a;
    // TestStateB b;

    // gameManager.pushState(&a);
    // gameManager.pushState(&b);

    int test = 0;
    Player testPlayer(renderer, 600, 400, 50, 50, 0, 0, 10, 1.5, "./Assets/Player/a");

    while (run) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }
            testPlayer.move(event);
        }

        // gameManager.tick();
        // test++;

        // if(test == 10) {
        //   gameManager.popState();
        // }

        // if(test == 20) {
        //   run = false;
        // }
        draw(renderer, testPlayer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
