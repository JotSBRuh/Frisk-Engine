#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Math.hpp>

class Entity
{
public:
	Entity(v::Vector2f p_pos, SDL_Texture* p_tex);
	v::Vector2f& getPos()
	{
		return pos;
	}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	v::Vector2f pos;

	SDL_Rect currentFrame;
	SDL_Texture* tex;
};