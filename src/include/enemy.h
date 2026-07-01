#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Enemy() {}
};

#endif