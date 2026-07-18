#ifndef ACTORPLAYER_H
#define ACTORPLAYER_H

#include "GameDefs.h"
#include "Player.h"
#include "Sprite.h"
#include "Weapons/WeaponDefs.h"

#include <SDL3/SDL_scancode.h>
#include <cstdint>

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
	Sprite *m_sprite = new Sprite("assets/img/stg_story.bmp");	SDL_Event *event;

	SDL_Gamepad *m_gamepad;

	WeaponsList weapons[POLAR];
};

#endif