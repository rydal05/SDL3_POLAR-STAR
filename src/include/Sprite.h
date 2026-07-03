#ifndef SPRITE_H
#define SPRITE_H

#include <SDL3/SDL.h>
#include <string>

class Sprite {
public:
	Sprite(const char *filepath);
	~Sprite();

	void Draw_Src(float x, float y, float w, float h);
	void Draw_Dst(float x, float y);
	void Draw_Siz(float w, float h);
	void Update(double dt);
	void Render();
	SDL_Texture *GetTexture() { return m_texture; }

	SDL_FRect m_dst;
private:
	SDL_FRect m_src;
	SDL_Texture *m_texture;
};

class AnimatedSprite {
public:
	AnimatedSprite(std::string filepath);

	~AnimatedSprite();

	void Draw(int x, int y, int w, int h);

	void PlayFrame(int x, int y, int w, int h, int frame);

	void Update();

	void Render(); //TODO: migrate rendering system from using passed in renderer (global, reference, etc) to using shared pointer stored in class

private:
	SDL_FRect m_src;
	SDL_Texture *m_texture;
};

#endif