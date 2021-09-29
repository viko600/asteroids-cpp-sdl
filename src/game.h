#if !defined(GAME)
#define GAME

#include "SDL2/SDL.h"
#include <iostream>
#include <memory>

#include "ship.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


class Game {
public:
    Game();
    ~Game();

    void init(const char* title, bool fullScreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    static SDL_Rect* GetRect(SDL_Texture* const texture, const int x, const int y);
    static SDL_Renderer* defaultRender;

private:
    bool isRunning;
    SDL_Window* _window;
    SDL_Renderer* _render;
    std::unique_ptr<Ship> ship;
};



#endif // GAME
