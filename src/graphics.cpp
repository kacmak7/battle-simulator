#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(this->SCREEN_WIDTH, this->SCREEN_HEIGHT, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "Battle");
}

Graphics::~Graphics() {
	//SDL_DestroyWindow(this->window);
	//SDL_DestroyRenderer(this->renderer);
}

const int Graphics::SCREEN_WIDTH = 1280;
const int Graphics::SCREEN_HEIGHT = 720;

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

void Graphics::drawPoint(int x, int y) {
    SDL_RenderDrawPoint(this->renderer, x, y);
}

void Graphics::setDrawColor(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->renderer;
}

SDL_Window* Graphics::getWindow() const {
    return this->window;
};
