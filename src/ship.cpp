#include "ship.h"
#include "game.h"


Ship::Ship(float x, float y, float s_r, SDL_Renderer* render) {
    _shipImg = IMG_Load("assets/ship.png");
    if(_shipImg == NULL){
        std::cerr << "ERROR: image load failed: " << SDL_GetError() << std::endl;
    }
    _ship = SDL_CreateTextureFromSurface(render, _shipImg);
    SDL_FreeSurface(_shipImg);
    _rect = Game::GetRect(_ship, x, y);
    _rect->w /= 32;
	_rect->h /= 32;
	_rect->w *= s_r;
	_rect->h *= s_r;

    // radius = ((float)_rect->w * .5) *.75;

    // radius_rect->w = radius*2;
	// radius_rect->h = radius*2;
	// radius_rect->x -= radius;
	// radius_rect->y -= radius;
}

Ship::~Ship() {}

void Ship::update(int dt) {
    std::cout << "rect\n";
}

void Ship::draw() {
    std::cout << "draw\n";
    SDL_RenderCopyEx(Game::defaultRender, _ship, NULL, _rect, angle, &center, SDL_FLIP_NONE); 
}