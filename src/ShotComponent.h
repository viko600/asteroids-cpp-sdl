#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "game.h"
#include "Components.h"
#include <algorithm>
#include <chrono>


class ShotComponent : public Component
{
public:
    ShotComponent() {
        tex = TextureManager::LaodTexture("assets/bullet.png");
        start = std::chrono::system_clock::now();
        next = std::chrono::system_clock::now();
    }

    void fire(int x, int y, double angle) {
        start = std::chrono::system_clock::now();
        if (start > next) {
            SDL_Rect shot;
            shot.w = 32;
            shot.h = 32;
            shot.x = x;
            shot.y = y;
            shots.push_back(shot);
            angles.push_back(angle);
            next = std::chrono::system_clock::now() + std::chrono::seconds(1);
        }
    }
    void update() override {
        for (size_t i = 0; i < shots.size(); i++) {
            shots[i].x += sin(angles[i] * PI/180) * 6;
            shots[i].y += -cos(angles[i] * PI/180) * 6;
            if (shots[i].x < 0 || 
            shots[i].x > SCREEN_WIDTH ||
            shots[i].y < 0 ||
            shots[i].y > SCREEN_HEIGHT) {
                shots.erase(shots.begin() + i);
                angles.erase(angles.begin() + i);
            }

        }
    }
    void draw() override {
        for (size_t i = 0; i < shots.size(); i++) {
            TextureManager::Draw(tex, srcR, shots[i], angles[i], center, flip);
        }
    }

    std::vector<SDL_Rect> shots;
    std::vector<double> angles;

private:
    SDL_Texture *tex;
    SDL_Rect srcR;
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    std::chrono::system_clock::time_point start, next;

};