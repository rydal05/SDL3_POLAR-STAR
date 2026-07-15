#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    virtual void update(double dt) = 0;
    virtual void render() = 0;
    virtual ~Weapon() {}
};


#endif