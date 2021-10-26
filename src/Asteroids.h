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
    std::vector<Entity> asteroids;
};