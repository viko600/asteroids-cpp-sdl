#include "game.h"
#include "Asteroids.h"

Asteroids::Asteroids(){}

void Asteroids::init() {
    spawnNew();
}

void Asteroids::draw() {
    for (auto& i : asteroids){
        i.draw();
    }
}

void Asteroids::update() {
    for (auto& i : asteroids){
        i.update();
    }
    refresh();
    start = std::chrono::system_clock::now();
    if (start > next) {
        spawnNew();
    }
}

void Asteroids::refresh() {
    asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(),
                    [](Entity &a){
                        return !a.isActive();
                    }
                ),
        asteroids.end());

}

void Asteroids::destroy(Entity &asteroid) {
    if (asteroid.getComponent<PositionComponent>().scale > 1) {
        spawnNewOnPosition(
            asteroid.getComponent<PositionComponent>().position.x,
            asteroid.getComponent<PositionComponent>().position.y,
            asteroid.getComponent<PositionComponent>().scale - 1
        );
        // spawnNewOnPosition(
        //     asteroid.getComponent<PositionComponent>().position.x,
        //     asteroid.getComponent<PositionComponent>().position.y,
        //     asteroid.getComponent<PositionComponent>().scale - 1
        // );

    }
    asteroid.destroy();
}

void Asteroids::spawnNew() {
    auto& ast(Game::manager.addNewEntity());
    asteroids.emplace_back(std::move(ast));
    asteroids.back().addComponent<PositionComponent>(
        randomFloat(0, SCREEN_HEIGHT),
        (float)randomNumber(0, SCREEN_WIDTH)
        ,32,32,
        (int)randomFloat(1, 3));
    asteroids.back().addComponent<SpriteComponent>("assets/asteroid2.png");
    asteroids.back().addComponent<ColisionComponent>("asteroid");
    asteroids.back().getComponent<PositionComponent>().velocity.x = randomFloat(-1.0, 1.0);
    asteroids.back().getComponent<PositionComponent>().velocity.y = randomFloat(-1.0, 1.0);
    next = std::chrono::system_clock::now() + std::chrono::seconds(3);

}

void Asteroids::spawnNewOnPosition(float x, float y, int size) {
    auto& ast(Game::manager.addNewEntity());
    asteroids.emplace_back(std::move(ast));
    asteroids.back().addComponent<PositionComponent>(
        x,
        y,
        32,32,
        size);
    asteroids.back().addComponent<SpriteComponent>("assets/asteroid2.png");
    asteroids.back().addComponent<ColisionComponent>("asteroid");
    asteroids.back().getComponent<PositionComponent>().velocity.x = randomFloat(-1.0, 1.0);
    asteroids.back().getComponent<PositionComponent>().velocity.y = randomFloat(-1.0, 1.0);
}

int Asteroids::randomNumber(int min, int max){
    int random = rand()%(max-min+1)+min;
    if (random > 10) return SCREEN_WIDTH;
    return 0;
}

float Asteroids::randomFloat(float min, float max){
    return (min + 1) + (((float) rand()) / (float) RAND_MAX) * (max - (min + 1)); 
}
