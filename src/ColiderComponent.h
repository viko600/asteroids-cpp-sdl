#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "Components.h"

class ColisionComponent : public Component
{
    SDL_Rect collider;
    std::string tag;

    PositionComponent *position;

    void init() override {
        if(!entity->hasComponent<PositionComponent>()){
            entity->addComponent<PositionComponent>();
        }

        position = &entity->getComponent<PositionComponent>();
    }

    void update() override {
        collider.x = position->position.x;
        collider.y = position->position.y;
        collider.w = position->width * position->scale;
        collider.h = position->heigh * position->scale;
    }
};