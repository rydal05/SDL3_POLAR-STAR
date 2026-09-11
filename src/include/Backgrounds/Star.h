#ifndef STAR_H
#define STAR_H

#include "GameDefs.h"
#include "superclasses/Entity.h"
#include "superclasses/Sprite.h"
#include <memory>
#include <vector>

class Star : public Entity {
public:
	Star();

	~Star();

	void Update(double dt) override;

	void Render() override;

	void setSpeed(float num, float size);

private:
	float speed = 0.0f;
};

#endif