#ifndef ACTORPLAYER_H
#define ACTORPLAYER_H

#include "GameDefs.h"
#include "Weapons/WeaponDefs.h"
#include "superclasses/Entity.h"
#include "superclasses/Sprite.h"
#include "superclasses/Weapon.h"
#include "superclasses/Bullet.h"

#include <SDL3/SDL_scancode.h>
#include <cstdint>

class ActorPlayer : public Entity {
public:
	ActorPlayer();
	explicit ActorPlayer(const char *filepath);

	virtual void Update(double dt) override;
	virtual void Render() override;

	void move(float x, float y);
	void movement(const bool *state, double dt);
	void inputs(const bool *state, double dt);

	void collision(const bool *state);

	void swapWeaponLeft(const bool *state);
	void swapWeaponRight(const bool *state);

	void shoot(const bool *state);
	void tapFire();
	void chargeFire();
	void rapidFire();

protected:
	SDL_FPoint coreOffset{8.0f, 10.0f};
	SDL_Gamepad *m_gamepad;
	Weapon *arsenal[(int)(weapondefs::WEAPON_LIST_SIZE)] = {NULL}; //weapons are now a dedicated type of memory
	
	int chargeLevel;
	bool held;
	std::uint16_t heldFrames;
	std::uint8_t weaponIDX;
	Bullet *bulletArray = NULL; //probbaly converting this to a vector
};

#endif