#ifndef WEAPON_H
#define WEAPON_H

#include "superclasses/Entity.h"

class Weapon {
public:
	Weapon();
	explicit Weapon(const char *filepath);

	virtual void Update(double dt) = 0; // update loop will interpret inputs and correspond weapon attack outputs
	virtual void Render() = 0;
	virtual void Shoot() = 0; // global export for handling what bullets get added to the players bullet queue and in turn get managed (updated & rendered) 
	
	virtual ~Weapon() {}



protected:
	Entity *owner = NULL;
};

#endif