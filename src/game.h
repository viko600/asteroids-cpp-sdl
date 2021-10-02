#if !defined(GAME)
#define GAME

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>


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
    int cnt{0};
    SDL_Texture* playerTex;
    SDL_Rect srcR, destR;
};



#endif // GAME
