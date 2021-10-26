#include "Shot.h"
#include "game.h"
#include <cmath>


void ShotComponent::init() {
    destR.x = static_cast<int>(entity->getComponent<PositionComponent>().position.x);
    destR.y = static_cast<int>(entity->getComponent<PositionComponent>().position.y);
    angle = static_cast<double>(entity->getComponent<PositionComponent>().angle);

    TextureManager::Draw(tex, srcR, destR, angle, center, flip);
    
}

void ShotComponent::update() {
    destR.x += sin(angle) * 3;
    destR.y += -cos(angle) * 3;

    if (destR.x < 0 || 
    destR.x > SCREEN_WIDTH ||
    destR.y < 0 ||
    destR.y > SCREEN_HEIGHT) {
        destroy();
    }
}

void ShotComponent::destroy() {
    SDL_DestroyTexture(tex);
}