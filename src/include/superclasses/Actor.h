// a class interface specifically for things that can shoot and interact with the world (distinguished by entities by the fact that entities are literally everything) this encompasses both players and enemies which hold bullet arrays

//im doing this later because i really do not feel like implementing this hahahahahah
#include "superclasses/Entity.h"
#include "Bullet.h"

class Actor : public Entity{
    Actor();
    explicit Actor(const char *filepath);

    protected:
        Actor(const char *path) : Entity(path) {}
        Bullet *bulletArray = NULL;
};