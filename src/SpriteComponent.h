#pragma once

#include "Components.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        text = TextureManager::LaodTexture(path);
    }

    void init() override {

        position = &entity->getComponent<PositionComponent>();

        srcRec.x = srcRec.y = 0;
        srcRec.w = srcRec.h = 32;
        destRec.w = destRec.h = 64;
    };
    void update() override {
        destRec.x = (int)position->position.x;
        destRec.y = (int)position->position.y;
    };
    void draw() override {
        TextureManager::Draw(text, srcRec, destRec, position->angle(), position->getCenter(), position->getFlip());
    };


private:
    PositionComponent *position;
    SDL_Texture *text;
    SDL_Rect srcRec, destRec;
};