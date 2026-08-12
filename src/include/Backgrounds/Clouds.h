#ifndef CLOUD_H
#define CLOUD_H

#include "superclasses/Entity.h"
#include "GameDefs.h"
#include "superclasses/Sprite.h"
#include <memory>
#include <unordered_map>
#include <vector> //TODO: needs to be made singleton 

//TODO: possibly migrate this to an overhead class for collection of entities (factory probably)

class Clouds {
public:
	Clouds();
	~Clouds();

	void Update(double dt);
	void Render();
	
private:
	float maxSpeed = 1.0f;
	std::vector<std::unique_ptr<Sprite>> cloudsBG;
	std::vector<float> cloud_speeds = {0.1f * maxSpeed, 0.2f * maxSpeed, 0.3f * maxSpeed, 0.5f * maxSpeed};
};

#endif