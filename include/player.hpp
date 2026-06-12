#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Sprite.hpp"

class Bullet;

class Player {
public:
	Player();
	void Update(double dt, Bullet &bullet);
	void Render();

	SDL_FRect &m_dst;

private:
	Sprite m_sprite;
	double m_fireCooldown;
};

#endif
