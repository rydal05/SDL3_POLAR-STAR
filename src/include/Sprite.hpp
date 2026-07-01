#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL3/SDL.h>
#include <string>

class Sprite {
public:
	Sprite(const char *filepath);
	~Sprite();

	void Draw_Src(int x, int y, int w, int h);
	void Draw_Dst(int x, int y);
	void Draw_Siz(int w, int h);
	void Update(double dt);
	void Render();
	SDL_Texture *GetTexture() { return m_texture; }

	SDL_FRect m_dst; // move to private when i have a better method of moving the player lol

private:
	SDL_FRect m_src;
	SDL_Texture *m_texture;
};

class AnimatedSprite {
public:
	AnimatedSprite(SDL_Renderer *&renderer, std::string filepath);

	~AnimatedSprite();

	void Draw(int x, int y, int w, int h);

	void PlayFrame(int x, int y, int w, int h, int frame);

	void Update();

	void Render(SDL_Renderer *&renderer);

private:
	SDL_FRect m_src;
	SDL_Texture *m_texture;
};

#endif
