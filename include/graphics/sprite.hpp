/**
 * Class defining image loading for sprites
 */

#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <string>

#include <SDL.h>

#include <graphics/graphic.hpp>

class Sprite : public Graphic {
protected:
	SDL_Texture * texture;

public:
	Sprite(const char * path_to_sprite, const Color&, SDL_Renderer *);
	Sprite(std::string path_to_sprite, const Color&, SDL_Renderer *);
	~Sprite();

	virtual SDL_Texture * getTexture();

	void setColorMod(const Color&);
	void setAlpha(uint8_t);
	void setBlendingMode(SDL_BlendMode);
};
#endif
