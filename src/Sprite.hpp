#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "gamedefs.hpp"
#include <SDL3/SDL.h>
#include <string>

class Sprite {
public:
	Sprite(const char *filepath);
	~Sprite();

	void Draw_Src(int x, int y, int w, int h);
	void Draw_Dst(int x, int y, int w, int h);
	void Update(double dt);
	void Render();
	SDL_Texture *GetTexture() { return m_texture; }

	SDL_FRect m_dst; // move to private when i have a better method of moving the player lol

private:
	SDL_FRect m_src;
	SDL_Texture *m_texture;
};

#endif
