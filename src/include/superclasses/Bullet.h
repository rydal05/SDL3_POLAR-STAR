#ifndef BULLET_H
#define BULLET_H

/*
RESPONSIBILITIES OF A BULLET:

1: Use math to determine path of travel using functions and whatever else
2: Manage rendering style PER BULLET
3: Maintain info that is pertinent per bullet such as damage, travel speed, etc.
4: Handle and reconcile collisions
5: Handle and reconcile ownership
*/

#include "superclasses/Entity.h"

class Bullet : public Entity {
public:
	Bullet();
	explicit Bullet(const char *filepath);

	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	
	void move(float x, float y);

	void travel();
	bool collision();

private:
};

#endif