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

#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(SDL_Renderer* renderer, int x, int y, int width, int height, int vx, int vy, float scale, string imageBasePath)
    : GameObject(renderer, x, y, width, height, vx, vy, scale), imageBasePath(imageBasePath), currImageDisplayedFrameCount(0),  FRAMES_PER_IMAGE(30), angle(0.0f) {
        textureImage1 = loadImage(imageBasePath + "1.png");
        textureImage2 = loadImage(imageBasePath + "2.png");
        currTexture = textureImage1;
}

Player::~Player() {
    if (textureImage1) {
        SDL_DestroyTexture(textureImage1);
    }
    if (textureImage2) {
        SDL_DestroyTexture(textureImage2);
    }
}

void Player::draw() {
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderCopyEx(renderer, currTexture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
    if (vx != 0 || vy != 0) {
        if (currImageDisplayedFrameCount >= FRAMES_PER_IMAGE) {
            currTexture = currTexture == textureImage1 ? textureImage2 : textureImage1;
            currImageDisplayedFrameCount = 0;
        } else {
            currImageDisplayedFrameCount++;
        }
    } else {
        if (currTexture != textureImage1) {
            currTexture = textureImage1;
            currImageDisplayedFrameCount = 0;
        }
    }
    SDL_RenderCopyEx(renderer, currTexture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}