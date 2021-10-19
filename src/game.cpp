#include "game.h"
#include "TextureManager.h"
#include "Components.h"
#include "GameObject.h"
#include "Asteroids.h"


std::unique_ptr<GameObject> background;

Manager Game::manager;

auto& newPlayer(Game::manager.addNewEntity());

Asteroids a;

SDL_Event Game::event;

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

        newPlayer.addComponent<PositionComponent>(SCREEN_HEIGHT/2, SCREEN_WIDTH/2 , 32, 32, 1);
        newPlayer.addComponent<SpriteComponent>("assets/ship.png");
        newPlayer.addComponent<KeyboardControler>();


        a.init();

    }
    else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    
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
    Game::manager.update();
    a.update();
}

void Game::render() {
    SDL_RenderClear(defaultRender);
    background->Render();
    Game::manager.draw();
    a.draw();
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