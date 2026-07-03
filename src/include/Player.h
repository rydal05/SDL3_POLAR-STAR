#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Player() {}
};

#endif