#include "game.h"
#include <memory>

int main()
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    Game* game = new Game;

    game->init("Asteroids", false);
    while (game->running()){
        frameStart = SDL_GetTicks();
        // game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
}