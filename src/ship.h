#ifndef SHIP_H
#define SHIP_H

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
// #include "DelayTimer.h"

class Ship
{
public:
    // Ship();
    Ship(float x, float y, float angle, SDL_Renderer* render);
    ~Ship();

    void update(int dt);
    void draw();
    SDL_Texture* gettexture() { return _ship; };
private:
    SDL_Texture* _ship;
    SDL_Surface* _shipImg;
    SDL_Rect* _rect;
    float radius = 0;
    int angle = 0;
    SDL_Point center{0, 0};

	// DelayTimer flash{ 125.0f, true };
	// bool draw = true;

	int MAX_SPEED;
};

#endif