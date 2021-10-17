#pragma once
#include "Components.h"
#include "Vector.h"

class PositionComponent : public Component
{
private:
    int speed{3};
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

public:
    Vector2D position;
    Vector2D velocity;
    int heigh{32};
    int width{32};
    int scale{1};
    double angle{0};

    PositionComponent(){
        position.x = 0;
        position.y = 0;
    }
    PositionComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
    PositionComponent(float x, float y, int h, int w, int s) {
        position.x = x;
        position.y = y;
        heigh = h;
        width = w;
        scale = s;

    }

    SDL_Point* getCenter() { return center; }
    SDL_RendererFlip getFlip() { return flip; }

    void init() override {
        velocity.x = 0;
        velocity.y = 0;
        angle = 0;
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        if (position.x > SCREEN_WIDTH) position.x = 0;
        if (position.x < 0) position.x = SCREEN_WIDTH;
        if (position.y > SCREEN_HEIGHT) position.y = 0;
        if (position.y < 0) position.y = SCREEN_HEIGHT;
        if (angle > 360) angle = 1;
        if (angle < 0) angle = 359;
    }

    void setPosition(int x, int y) {
        position.x = x;
        position.y = y;
    }
};