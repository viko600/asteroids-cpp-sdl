#include "game.h"
#include "TextureManager.h"

Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, bool fullScreen) {

    int flag = fullScreen ? SDL_WINDOW_FULLSCREEN : 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsytems init" << std::endl;

        _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flag);
        if(_window){
            std::cout << "Window creaed" << std::endl;
        }

        _render = SDL_CreateRenderer(_window, -1, 0);
        if(_render){
            std::cout << "rendered" << std::endl;
            SDL_SetRenderDrawColor(_render, 0, 0, 0, 0);
        }
        isRunning = true;

        playerTex = TextureManager::LaodTexture("assets/ship.png", _render);

    }
    else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }

}

void Game::update() {
    
    cnt++;
    destR.h = 32;
    destR.w = 32;
    destR.x = cnt;
}

void Game::render() {
    SDL_RenderClear(_render);
    SDL_RenderCopy(_render, playerTex, NULL, &destR);
    SDL_RenderPresent(_render);
}

void Game::clean() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_render);
    SDL_Quit();
    std::cout << "Game closed" << std::endl;
} 


bool Game::running() { return isRunning; }

SDL_Rect* Game::GetRect(SDL_Texture* const texture, const int x, const int y)
{
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	SDL_Rect* rect = new SDL_Rect{ x, y, w, h };
	return rect;
}

SDL_Renderer* Game::defaultRender;