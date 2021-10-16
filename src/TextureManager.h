#pragma once
#include "game.h"

class TextureManager
{
public:
    static SDL_Texture* LaodTexture(const char* fileName);
    static void Draw(SDL_Texture *tex, SDL_Rect srcRect, SDL_Rect destRec, double angle, SDL_Point *center, SDL_RendererFlip flip);
};