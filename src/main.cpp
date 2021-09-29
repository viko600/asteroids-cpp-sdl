#include "game.h"
#include <memory>

int main()
{
    Game* game = new Game;

    game->init("Asteroids", false);
    while (game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
}