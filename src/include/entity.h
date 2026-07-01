#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Entity() {}
};

#endif