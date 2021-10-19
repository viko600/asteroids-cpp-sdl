#pragma once
#include <chrono>
#include "ECS.h"


class Asteroids
{
public:
    Asteroids();
    void init();
    void draw();
    void update();
private:
    std::vector<Entity> asteroids;
};