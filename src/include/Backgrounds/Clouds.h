#ifndef CLOUD_H
#define CLOUD_H

#include "Entity.h"
#include "GameDefs.h"
#include "Sprite.h"
#include <memory>
#include <unordered_map>
#include <vector>

class Clouds : public Entity {
public:
	Clouds();
    ~Clouds();

	void update(double dt) override;
	void render() override;

private:
	float speed = 1.0f + GameDefs::ScaleFactor;

	std::vector<std::unique_ptr<Sprite>> cloudsBG;
	std::vector<float> moon_speeds = {0.1f / speed, 0.2f / speed, 0.3f / speed, 0.5f / speed};
};

#endif