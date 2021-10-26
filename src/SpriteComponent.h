#pragma once

#include "Components.h"
#include <SDL2/SDL.h>
#include "TextureManager.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        text = TextureManager::LaodTexture(path);
    }
    ~SpriteComponent(){
        SDL_DestroyTexture(text);
    }

    void init() override {

        position = &entity->getComponent<PositionComponent>();

        srcRec.x = srcRec.y = 0;
        srcRec.w = srcRec.h = position->heigh;
        destRec.x = position->position.x;
        destRec.y = position->position.y;
        destRec.w = destRec.h = position->heigh * position->scale;

    };
    void update() override {
        destRec.x = (int)position->position.x;
        destRec.y = (int)position->position.y;
    };
    void draw() override {
        TextureManager::Draw(text, srcRec, destRec, position->angle, position->getCenter(), position->getFlip());
    };


private:
    PositionComponent *position;
    SDL_Texture *text;
    SDL_Rect srcRec, destRec;
};