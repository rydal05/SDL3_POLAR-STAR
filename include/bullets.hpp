#ifndef BULLETS_HPP
#define BULLETS_HPP

#include "Sprite.hpp"

class Bullet {
public:
	Bullet();
	void Reset(float x, float y);
	void Update(double dt);
	void Render();

	SDL_FRect &m_dst;

private:
	Sprite m_sprite;
	bool m_active;
};

#endif