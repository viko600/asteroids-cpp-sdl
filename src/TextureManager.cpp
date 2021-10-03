#include "TextureManager.h"

SDL_Texture* TextureManager::LaodTexture(const char* fileName)
{
    SDL_Surface* tempSurf = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::defaultRender, tempSurf);
    SDL_FreeSurface(tempSurf);

    return tex;
}