/**
 * Class defining abstract graphical interfaces.
 */

#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <SDL.h>

class Graphic {
public:
	virtual SDL_Texture * getTexture() = 0;
};

class Color {
public:
	uint8_t red;
	uint8_t blue;
	uint8_t green;

	Color(uint8_t, uint8_t, uint8_t);
	Color(uint32_t);
};
#endif