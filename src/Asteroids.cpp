#include "game.h"
#include "Asteroids.h"

Asteroids::Asteroids(){
    // auto& ast(Game::manager.addNewEntity());
    // asteroids.emplace_back(std::move(ast));
}

void Asteroids::init() {
    // asteroids[0].addComponent<PositionComponent>(100,100,32,32,1);
    // asteroids[0].addComponent<SpriteComponent>("assets/asteroid2.png");
    // asteroids[0].addComponent<ColisionComponent>("asteroid");
    // asteroids[0].getComponent<PositionComponent>().velocity.x = 1;
    // asteroids[0].getComponent<PositionComponent>().velocity.y = 0.13;
    // next = std::chrono::system_clock::now() + std::chrono::seconds(3);

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
    if (asteroid.getComponent<PositionComponent>().scale < 2) asteroid.destroy();

}

void Asteroids::spawnNew() {
    auto& ast(Game::manager.addNewEntity());
    asteroids.emplace_back(std::move(ast));
    asteroids.back().addComponent<PositionComponent>(
        randomNumber(0, SCREEN_HEIGHT),
        randomNumber(0, SCREEN_WIDTH)
        ,32,32,
        randomNumber(1, 3));
    asteroids.back().addComponent<SpriteComponent>("assets/asteroid2.png");
    asteroids.back().addComponent<ColisionComponent>("asteroid");
    asteroids.back().getComponent<PositionComponent>().velocity.x = 1;
    asteroids.back().getComponent<PositionComponent>().velocity.y = 0.13;
    next = std::chrono::system_clock::now() + std::chrono::seconds(3);

}

int Asteroids::randomNumber(int min, int max){
    return rand()%(max-min+1)+min;
}
