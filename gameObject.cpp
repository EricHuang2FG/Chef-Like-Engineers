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
#include "GameObject.h"
using namespace std;

SDL_Texture* GameObject::loadImage(const string& path) {
    SDL_Texture* newImage = nullptr;
    newImage = IMG_LoadTexture(renderer, path.c_str());
    return newImage;
}
