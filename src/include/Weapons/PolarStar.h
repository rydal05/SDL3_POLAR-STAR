#ifndef POLAR_STAR_H
#define POLAR_STAR_H

#include "WeaponDefs.h"
#include "superclasses/Entity.h"
#include "superclasses/Weapon.h"
class PolarStar : public Weapon {
public:
	PolarStar(Entity *callee) : Weapon("assets/img/Polar_Star_Players.bmp") {

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

	private:
		float stats[(int)(weapondefs::STATS_SIZE)][4] = {0};
};

#endif