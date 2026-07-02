#ifndef BULLET_H
#define BULLET_H

class Bullet {
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Bullet() {}
};

#endif