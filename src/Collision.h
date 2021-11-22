#pragma once

#include <SDL2/SDL.h>

class Collision
{
public:
    static bool AABB(SDL_Rect &rectOne, SDL_Rect &rectTwo);
};