#pragma once

#include "game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardControler : public Component
{
public:
    PositionComponent *position;

    void init() override {
        position = &entity->getComponent<PositionComponent>();
    }

    void update() override {
        if (Game::event.type == SDL_KEYDOWN){
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w :
                position->velocity.y = -1;
                break;
            case SDLK_a:
                position->angle -= 3;
                break;
            case SDLK_d:
                position->angle += 3;
                break;
            default:
                break;
            }
        }
        if (Game::event.type == SDL_KEYUP){
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w :
                position->velocity.y = 0;
                break;
            default:
                break;
            }
        }
        if (SDL_MOUSEMOTION){
            std::cout << Game::event.motion.x << std::endl;
            std::cout << Game::event.motion.y << std::endl;
        }
    }

private:
};