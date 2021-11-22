#include "TextureManager.h"

SDL_Texture* TextureManager::LaodTexture(const char* fileName)
{
    SDL_Surface* tempSurf = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::defaultRender, tempSurf);
    SDL_FreeSurface(tempSurf);

    return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect srcRec, SDL_Rect destRect, double angle, SDL_Point *center, SDL_RendererFlip flip){
    SDL_RenderCopyEx(Game::defaultRender, tex, NULL, &destRect, angle, center, flip);
}