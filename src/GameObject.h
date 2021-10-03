#pragma once
#include "game.h"

class GameObject
{
public:
    GameObject(const char* texturesheet, int x, int y, int w, int h);
    ~GameObject();

    void Update();
    void Render();

private:
    int x_pos;
    int y_pos;
    int width, height;
    double angle{0.0};

    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Texture* objTex;
    SDL_Rect srcR, destR;
};