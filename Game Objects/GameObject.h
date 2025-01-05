#pragma once
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
#include "../Constants.h"
using namespace std;

class GameObject {
    protected:
        int x, y;
        int width, height;
        int vx, vy;
        float scale;
        SDL_Renderer* renderer;

    public:
        GameObject(SDL_Renderer* renderer, int x = SCREEN_WIDTH / 2, int y = SCREEN_HEIGHT / 2, int width = 50, int height = 50, int vx = 0, int vy = 0, float scale = 1.0)
            : renderer(renderer), x(x), y(y), width(width), height(height), vx(vx), vy(vy), scale(scale) {}
        // default values for x and y are not strictly in the middle of the screen, but that's fine

        virtual ~GameObject() {}

        virtual SDL_Texture* loadImage(const string& path);
};
