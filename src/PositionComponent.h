#pragma once
#include "Vector.h"
#include "game.h"
#include "Components.h"

class PositionComponent : public Component
{
private:
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

public:
    Vector2D position;
    Vector2D velocity;
    int heigh{32};
    int width{32};
    int scale{1};
    float angle{0};
    std::string tag = "player";

    PositionComponent(){
        position.x = 0;
        position.y = 0;
        
    }
    PositionComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
    PositionComponent(float x, float y, int h, int w, int s, float a) {
        position.x = x;
        position.y = y;
        heigh = h;
        width = w;
        scale = s;
        angle = a;
    }

    SDL_Point* getCenter() { return center; }
    SDL_RendererFlip getFlip() { return flip; }

    void init() override {
        // velocity.x = 0;
        // velocity.y = 0;
        // angle = 0;
    }

    void update() override {
        position.x += velocity.x * sin(angle*PI/180);
        position.y += velocity.y * -cos(angle*PI/180);
        if (position.x > SCREEN_WIDTH) position.x = 0;
        if (position.x < 0) position.x = SCREEN_WIDTH;
        if (position.y > SCREEN_HEIGHT) position.y = 0;
        if (position.y < 0) position.y = SCREEN_HEIGHT;
        if (tag == "player")
        {
            velocity.x -= velocity.x * 0.05;
            velocity.y -= velocity.y * 0.05;
        }
    }

    void setPosition(int x, int y) {
        position.x = x;
        position.y = y;
    }
};