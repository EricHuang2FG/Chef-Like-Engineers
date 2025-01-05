#pragma once
#ifdef WINDOWS
  #define SDL_MAIN_HANDLED
  #include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_ttf.h>
  #include <SDL_mixer.h>
  #include <iostream>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
  #include <SDL2/SDL_ttf.h>
  #include <SDL2/SDL_mixer.h>
#endif 

#include <iostream>
#include <GameObject.h>
using namespace std;

class Player: public GameObject {
    private:
        int x, y;
        int width, height;
        SDL_Texture* texture;
        SDL_Renderer* renderer;
};