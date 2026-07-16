#ifndef ACTORPLAYER_H
#define ACTORPLAYER_H

#include "GameDefs.h"
#include "Player.h"
#include "Sprite.h"
#include "Weapons/WeaponDefs.h"

#include <cstdint>
#include <SDL3/SDL_scancode.h>



class ActorPlayer : public Player {
public:
	ActorPlayer();
	void update(double dt) override;
	void render() override;
	void move(float x, float y);
	
	void movement(const bool *state, double dt);
	void collision(const bool *state);
	void swapWeapon(const bool *state);
	void shoot(const bool *state);

protected:
	Sprite m_sprite;
	SDL_FRect m_dst;
	SDL_Event *event;

	SDL_Gamepad *m_gamepad;
	float SPEED = 0.250f;

	WeaponsList weapons[POLAR];	
};

#endif