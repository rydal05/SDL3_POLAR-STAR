#ifndef POLAR_STAR_H
#define POLAR_STAR_H

#include "Weapon.h"

class PolarStar : public Weapon {
public:
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~PolarStar() {}
};

#endif