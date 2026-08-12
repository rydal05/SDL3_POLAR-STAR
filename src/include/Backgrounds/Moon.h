#ifndef MOON_H
#define MOON_H

#include <cmath>
#include <cstdlib>
#include <memory>

#include "superclasses/Entity.h"
#include "GameDefs.h" //TODO: needs to be made singleton and proabbly more acurately named as a bg asset manager
#include "superclasses/Sprite.h"

class Moon : public Entity {
public:
	Moon();
	~Moon();

	void Update(double dt) override;
	void Render() override;

private:
	float baseSpeed = .001f;
	bool direction = true;
	
    
	float offsetX = 250.0f;
	float offsetY = 25.0f;
	
	float y = offsetY;
    float x = offsetX;
    
    float UB = offsetX + (25.0f);
	float LB = offsetX - (25.0f);
};

#endif