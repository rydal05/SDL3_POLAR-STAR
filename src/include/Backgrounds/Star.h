#ifndef STARS_H
#define STARS_H

#include "Entity.h"
#include "GameDefs.h"
#include "Sprite.h"
#include <memory>
#include <unordered_map>

class Star : public Entity {
public:
	Star();
	~Star();

	void update(double dt) override;
	void render() override;

private:
	float speed;

	Sprite *m_sprite;
};

#endif