#ifndef BULLET_H
#define BULLET_H

#include "superclasses/Entity.h"

class Bullet : public Entity {
public:
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~Bullet() {}
};

#endif