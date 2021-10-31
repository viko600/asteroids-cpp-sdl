#include "game.h"
#include "Asteroids.h"

Asteroids::Asteroids(){
    auto& ast(Game::manager.addNewEntity());
    asteroids.emplace_back(std::move(ast));
}

void Asteroids::init() {
    asteroids[0].addComponent<PositionComponent>(100,100,32,32,1);
    asteroids[0].addComponent<SpriteComponent>("assets/asteroid2.png");
    asteroids[0].addComponent<ColisionComponent>("asteroid");
    asteroids[0].getComponent<PositionComponent>().velocity.x = 1;
    asteroids[0].getComponent<PositionComponent>().velocity.y = 0.13;

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
}

void Asteroids::destroy(Entity &asteroid) {
    if (asteroid.getComponent<PositionComponent>().scale < 2) asteroid.destroy();

}