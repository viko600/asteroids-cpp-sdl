#include "Collision.h"

bool Collision::AABB(SDL_Rect &rOne, SDL_Rect &rTwo){
    if (
        rOne.x + rOne.w >= rTwo.x ||
        rTwo.x + rTwo.w >= rOne.x ||
        rOne.y + rOne.h >= rTwo.y ||
        rTwo.y + rTwo.h >= rOne.y
    ) {
        return true;
    }

    return false;
}