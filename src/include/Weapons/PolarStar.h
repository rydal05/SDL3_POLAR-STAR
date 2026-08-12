#ifndef POLAR_STAR_H
#define POLAR_STAR_H

#include "superclasses/Weapon.h"

class PolarStar : public Weapon {
public:
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~PolarStar() {}
};

#endif