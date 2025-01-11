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

#include "GameObject.h"
#include <iostream>
#include <string>
using namespace std;

class Player: public GameObject {
    private:
        SDL_Texture* textureImage1;
        SDL_Texture* textureImage2;
        SDL_Texture* currTexture;
        string imageBasePath;
        int currImageDisplayedFrameCount;
        const int FRAMES_PER_IMAGE;
        const int MAX_ANGULAR_VELOCITY;
        int angle; // 0 points to the top of the screen
    
    public:
        Player(SDL_Renderer* renderer, int x = SCREEN_WIDTH / 2, int y = SCREEN_HEIGHT / 2, int width = 50, int height = 50, int vx = 0, int vy = 0, int maxSpeed = 5, float scale = 1.0, string imageBasePath = "");
        
        ~Player();

        void draw();

        void setVelocityComponents();

        void move(const SDL_Event& e);
};
