#pragma once

#include <cmath>
#include "game.h"
#include "Components.h"

class KeyboardControler : public Component
{
public:
    PositionComponent *position;
    ShotComponent *shots;

    void init() override
    {
        position = &entity->getComponent<PositionComponent>();
        shots = &entity->getComponent<ShotComponent>();
    }

    void update() override
    {
        if (Game::event.type == SDL_KEYDOWN)
        {
            if (keyboard_state_array[SDL_SCANCODE_W])
            {
                position->velocity.x += 0.5;
                position->velocity.y += 0.5;
            }
            if (keyboard_state_array[SDL_SCANCODE_A])
            {
                position->angle -= 12.0f;
            }
            if (keyboard_state_array[SDL_SCANCODE_D])
            {
                position->angle += 12.0f;
            }
            if (keyboard_state_array[SDL_SCANCODE_SPACE])
            {
                shots->fire(position->position.x, position->position.y, position->angle);
            }
        }
    }

private:
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
};
