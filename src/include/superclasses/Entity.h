#ifndef ENTITY_H
#define ENTITY_H

#include "superclasses/Sprite.h"

class Entity {
public:
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~Entity() {}

	SDL_Texture *m_GetTexture() {
		return m_sprite->GetTexture();
	}

	Sprite *getSprite() {
		return this->m_sprite;
	}

protected:
	Entity(const char* path) : m_sprite(new Sprite(path)) {}
	Sprite *m_sprite;
};

#endif