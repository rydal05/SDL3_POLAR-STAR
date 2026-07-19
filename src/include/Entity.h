#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~Entity() {}
};

#endif