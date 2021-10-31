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
    void destroy(Entity &asteroid);
    std::vector<Entity> asteroids;
private:
    void spawnNew();
};