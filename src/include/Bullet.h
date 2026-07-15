#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Bullet() {}
};

#endif