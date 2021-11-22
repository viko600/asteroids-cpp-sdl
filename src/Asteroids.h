#pragma once
#include <chrono>
#include "Components.h"


class Asteroids : public Component
{
public:
    Asteroids();
    void init() override;
    void draw() override;
    void update() override;
    void refresh();
    void destroy(Entity &asteroid);
    std::vector<Entity> asteroids;
private:
    std::chrono::system_clock::time_point start, next;
    void spawnNew();
    void spawnNewOnPosition(float x, float y, int size);
    int randomNumber(int min, int max);
    float randomFloat(float min, float max);
};