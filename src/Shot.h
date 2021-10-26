#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "Components.h"
#include "game.h"

class ShotComponent : public Component
{
public:
    ShotComponent(std::string t) : tag{t} {
        tex = TextureManager::LaodTexture("assets/bullet.png");
    };
    void init() override;
    void update() override;
    void draw() override;
    void destroy();

    std::string tag;

private:
    SDL_Texture *tex;
    SDL_Rect srcR, destR;
    double angle;
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

};