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

#include <cmath>
#include "Player.h"
#include <iostream>
#include <string>
#include "../Constants.h"
using namespace std;

Player::Player(SDL_Renderer* renderer, int x, int y, int width, int height, int vx, int vy, int maxSpeed, float scale, string imageBasePath)
    : GameObject(renderer, x, y, width, height, vx, vy, maxSpeed, scale), imageBasePath(imageBasePath), currImageDisplayedFrameCount(0),  FRAMES_PER_IMAGE(60), angle(0), MAX_ANGULAR_VELOCITY(30.0) {
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
    SDL_Rect rect = { x, y, static_cast<int>(width * scale), static_cast<int>(height * scale)};
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
        }
        currImageDisplayedFrameCount = 0;
    }
    SDL_RenderCopyEx(renderer, currTexture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}

void Player::setVelocityComponents() {
    double angleRad = (fmod((double) angle, 360.0)) * M_PI / 180.0;
    vx = ((double) currSpeed) * sin(angleRad);
    vy = -((double) currSpeed) * cos(angleRad); // negative goes up

    if (x < 0) x = 0;
    if (x + scaledWidth > SCREEN_WIDTH) x = SCREEN_WIDTH - scaledWidth;
    if (y < 0) y = 0;
    if (y + scaledHeight > SCREEN_HEIGHT) y = SCREEN_HEIGHT - scaledHeight;
}

void Player::move(const SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_w) {
            currSpeed = maxSpeed;
        }
        if (e.key.keysym.sym == SDLK_s) {
            currSpeed = -maxSpeed;
        }
        if (e.key.keysym.sym == SDLK_a) {
            angle -= MAX_ANGULAR_VELOCITY;
        }
        if (e.key.keysym.sym == SDLK_d) {
            angle += MAX_ANGULAR_VELOCITY;
        }
    } else if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
            case SDLK_w:
            case SDLK_s:
                currSpeed = 0;
                break;
        }
    }

    setVelocityComponents();

    x += vx;
    y += vy;

}
