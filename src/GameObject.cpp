#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* t, int x, int y, int w, int h){
    objTex = TextureManager::LaodTexture(t);
    x_pos = x;
    y_pos = y;
    width = w;
    height = h;
}

GameObject::~GameObject(){}

void GameObject::Update(){

    x_pos++;
    y_pos++;

    srcR.h = height;
    srcR.w = width;
    srcR.x = 0;
    srcR.y = 0;

    destR.x = x_pos;
    destR.y = y_pos;
    destR.w = srcR.w * 2;
    destR.h = srcR.h * 2;
    angle++;
}

void GameObject::Render(){
    SDL_RenderCopyEx(Game::defaultRender, objTex, NULL, &destR, angle, center, flip);
}