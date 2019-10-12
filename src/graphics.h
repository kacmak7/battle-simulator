#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include <map>
#include <string>
#include "utils.h"

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	/* SDL_Surface* loadImage
	 * Loads an image into the _spriteSheets map if it doesn't already exist.
	 * As a result, each image will only ever be loaded once
	 * Returns the image from the map regardless of whether or not it was just loaded
	 */
	SDL_Surface* loadImage(const std::string &filePath);

	// Draws a texture to a certain part of the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	// Renders everything to the screen
	void flip();

	// Clears the screen
	void clean();

	// Lights up a pixel
	void drawPoint(Vector2 p);

	// Turns off a pixel
	void erasePoint(Vector2 p);

	// Sets a color of next drawings
	void setDrawColor(int r, int g, int b, int a);

	// Returns the renderer
	SDL_Renderer* getRenderer() const;

	// Returns the window
	SDL_Window* getWindow() const;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
