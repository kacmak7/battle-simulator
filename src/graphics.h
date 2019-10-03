#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

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
