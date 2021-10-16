#pragma once
#include "Components.h"
#include "Vector.h"

class PositionComponent : public Component
{
private:
    double _angle{0};
    int speed{3};
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

public:
    Vector2D position;
    Vector2D velocity;


    PositionComponent(){}
    PositionComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    double angle() { return _angle; }
    SDL_Point* getCenter() { return center; }
    SDL_RendererFlip getFlip() { return flip; }

    void init() override {
        position.x = 0;
        position.y = 0;
        velocity.x = 0;
        velocity.y = 0;
        _angle = 0;
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        if (position.x > SCREEN_WIDTH) position.x = 0;
        if (position.x < 0) position.x = SCREEN_WIDTH;
        if (position.y > SCREEN_HEIGHT) position.y = 0;
        if (position.y < 0) position.y = SCREEN_HEIGHT;
        _angle++;
    }

    void setPosition(int x, int y) {
        position.x = x;
        position.y = y;
    }
};