#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~Player() {}
};

#endif