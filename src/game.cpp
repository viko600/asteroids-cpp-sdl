#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "ECS.h"
#include "Components.h"


std::unique_ptr<GameObject> player;
std::unique_ptr<GameObject> enamy;
std::unique_ptr<GameObject> background;

Manager manager;
auto& newPlayer(manager.addNewEntity());

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

        defaultRender = SDL_CreateRenderer(_window, -1, 0);
        if(defaultRender){
            std::cout << "rendered" << std::endl;
            SDL_SetRenderDrawColor(defaultRender, 0, 0, 0, 0);
        }
        isRunning = true;

        background = std::make_unique<GameObject>("assets/space.png", 0, 0, 800, 640);
        background->Update();
        player = std::make_unique<GameObject>("assets/ship.png", 0, 0, 32, 32);

        newPlayer.addComponent<PositionComponent>();

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
    player->Update();
    manager.update();

}

void Game::render() {
    SDL_RenderClear(defaultRender);
    background->Render();
    player->Render();
    SDL_RenderPresent(defaultRender);
}

void Game::clean() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(defaultRender);
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

SDL_Renderer* Game::defaultRender = nullptr;