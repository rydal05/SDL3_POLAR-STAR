#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    virtual void Update(double dt) = 0;
    virtual void Render() = 0;
    virtual ~Weapon() {}
};


#endif