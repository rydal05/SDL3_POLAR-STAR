#ifndef POLAR_STAR_H
#define POLAR_STAR_H

#include "superclasses/Weapon.h"

class PolarStar : public Weapon {
public:
	PolarStar() : Weapon("assets/img/Polar_Star_Players.bmp") {
		
	}


	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~PolarStar() {}
};

#endif