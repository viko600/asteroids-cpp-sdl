#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "Components.h"

class ColisionComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;

    PositionComponent *position;

    ColisionComponent(std::string t) : tag{t} {};

    void init() override {
        if(!entity->hasComponent<PositionComponent>()){
            entity->addComponent<PositionComponent>();
        }

        position = &entity->getComponent<PositionComponent>();
    }

    void update() override {
        collider.x = static_cast<int> (position->position.x);
        collider.y = static_cast<int> (position->position.y);
        collider.w = static_cast<int> (position->width * position->scale);
        collider.h = static_cast<int> (position->heigh * position->scale);
    }
};