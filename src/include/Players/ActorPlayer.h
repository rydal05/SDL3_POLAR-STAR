#ifndef ACTORPLAYER_H
#define ACTORPLAYER_H

#include "GameDefs.h"
#include "Player.h"
#include "Sprite.h"
#include "Weapons/WeaponDefs.h"

#include <SDL3/SDL_scancode.h>
#include <cstdint>

class ActorPlayer : public Entity {
public:
	ActorPlayer();
	explicit ActorPlayer(const char* filepath);

	virtual void Update(double dt) override;
	virtual void Render() override;
	void move(float x, float y);

	void movement(const bool *state, double dt);
	void collision(const bool *state);
	void swapWeaponLeft(const bool *state);
	void swapWeaponRight(const bool *state);
	
	void shoot(const bool *state);
	void tapFire();
	void chargeFire();
	void rapidFire();


protected:
	SDL_FPoint coreOffset{8.0f,
						  10.0f};
	SDL_Gamepad *m_gamepad;
	Sprite *m_sprite;
	WeaponsList weapons[WEAPON_LIST_SIZE];

};

#endif