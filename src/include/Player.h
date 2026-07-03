#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    virtual void update(double dt) override;
    virtual void render() override;
    virtual ~Player() {}
};

#endif