#pragma once

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include "ECS.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640


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

    static Manager manager;
    static SDL_Event event;
    static SDL_Rect* GetRect(SDL_Texture* const texture, const int x, const int y);
    static SDL_Renderer* defaultRender;

private:
    bool isRunning;
    SDL_Window* _window;
};
