#ifndef POLAR_STAR_H
#define POLAR_STAR_H

#include "WeaponDefs.h"
#include "superclasses/Entity.h"
#include "superclasses/Weapon.h"
class PolarStar : public Weapon {
public:
	PolarStar(Entity* callee) : Weapon("assets/img/Polar_Star_Players.bmp") {
		stats[FIRE_RATE][POLAR] = 1;
		stats[AMMO_MAX][POLAR] = 1;
		stats[DAMAGE_LEVEL_ONE][POLAR] = 1;
		stats[DAMAGE_LEVEL_TWO][POLAR] = 2;
		stats[DAMAGE_LEVEL_THREE][POLAR] = 3;
		stats[XP_REQUIRED_TWO][POLAR] = 1;
		stats[XP_REQUIRED_THREE][POLAR] = 1;
		stats[AMMO_PICKUP_SIZE][POLAR] = 1;


		this->owner = callee;
		// ok so i can either explicitly state weapon stats in here but that FEELS intrinically wasteful like I don't know if it would be better to manage that entirely within the weapondefs header but in here it is a lot easier to look at specific stats for weapons when i want to rather than looking through a giant disgusting list
	}
	~PolarStar() {}

	virtual void Update(double dt) override {
		// doi nitgiung
	};
	virtual void Render() override {
		// do nothing
	};

	void Shoot() {
		SDL_Log("FIRED FROM POLARSTAR  UNSPECIFIED SHOT TYPE");
	}
};

#endif