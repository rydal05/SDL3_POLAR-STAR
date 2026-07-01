#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Player() {}
};

#endif