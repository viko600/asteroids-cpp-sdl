#pragma once

#include <cmath>
#include "game.h"
// #include "ECS.h"
#include "Components.h"


class KeyboardControler : public Component
{
public:
    PositionComponent *position;
    ShotComponent *shots;

    void init() override {
        position = &entity->getComponent<PositionComponent>();
        shots = &entity->getComponent<ShotComponent>();
    }

    void update() override {
        if (Game::event.type == SDL_KEYDOWN){
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w :
                position->velocity.x = sin(position->angle*PI/180);
                position->velocity.y = -cos(position->angle*PI/180);
                break;
            case SDLK_a:
                position->angle -= 5.0f;
                break;
            case SDLK_d:
                position->angle += 5.0f;
                break;
            case SDLK_SPACE:
                shots->fire(position->position.x, position->position.y, position->angle);
                break;
            default:
                break;
            }
        }
        if (Game::event.type == SDL_KEYUP){
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w :
                position->velocity.x = 0;
                position->velocity.y = 0;
                break;
            default:
                break;
            }
        }
    }

};