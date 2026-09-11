#ifndef WEAPON_H
#define WEAPON_H

#include "superclasses/Entity.h"

class Weapon : public Sprite{ //weapons are a literal sprite class on top of being functional for actual bullet shooting, this just gives us a way to abstract away the physical gun appearance and rendering separate from needing a player sprite for that specific weapon
public:
	Weapon();
	explicit Weapon(const char *filepath);

	virtual void Update(double dt) = 0; // update loop will interpret inputs and correspond weapon attack outputs
	virtual void Render() = 0;
	
	virtual void Shoot() = 0;
	// virtual void Hold() = 0;

	virtual ~Weapon() = default;

protected:
	Entity *owner = NULL;
};

#endif