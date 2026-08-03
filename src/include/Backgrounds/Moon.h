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
	Moon() : Entity("assets/img/moon_stars_polarstar.bmp") {
		m_sprite->Draw_Src(10.0f, 0.0f, 34.0f, 34.0f);
		// pos 10 0
		// size 34 x 34
		// moon->Draw_Dst(0.0f, 0.0f);
		m_sprite->Draw_Siz(34.0f, 34.0f);
	}
	~Moon() {
		SDL_free(this->m_sprite);
	}

	void Update(double dt) override {
		// y = x whatever whatever function or reverse to accomplish what it is i want here

		float speed = baseSpeed * (float)dt;

		float stretchH = 10.0f;
		float strecthW = 5.0f;

		switch (direction) {
			case (true): {
				y = (stretchH * ((sin(x + offsetX)) / (strecthW))) + offsetY; // SINE WAVE FUNCTION
				x += speed;
				break;
			}
			case (false): {
				y = -(stretchH * (sin(x + offsetX) / (strecthW))) + offsetY; // LEGAL CODE
				x -= speed;
				break;
			}
		}

		if (x > UB) direction = false;

		if (x < LB) direction = true;

		// SDL_Log("XY POS %.2f %.2f", x, y);
		m_sprite->Draw_Dst(x, y);
	}
	void Render() override {
		m_sprite->Render();
	}

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