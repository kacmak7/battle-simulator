#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "globals.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "Battle");
}

Graphics::~Graphics() {
	//SDL_DestroyWindow(this->window);
	//SDL_DestroyRenderer(this->renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	if (this->_spriteSheets.count(filePath) == 0) {
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(this->renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->renderer);
}

void Graphics::clean() {
	SDL_RenderClear(this->renderer);
}

void Graphics::drawRectangle(int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

//TODO: to decide what to do with that
//void Graphics::setDrawColor(int r, int g, int b, int a) {
//    SDLRenderDrawColor(renderer, r, g, b, a)
//}

//void Graphics::setDrawColorToDefault() {
//    SDLRenderDrawColor(renderer, 0, 0, 0, 255);
//}

SDL_Renderer* Graphics::getRenderer() const {
	return this->renderer;
}

SDL_Window* Graphics::getWindow() const {
    return this->window;
};
