#ifndef STAR_H
#define STAR_H

#include "superclasses/Entity.h"
#include "GameDefs.h"
#include "superclasses/Sprite.h"
#include <memory>
#include <vector>

class Star : public Entity {
public:
	Star() : Entity("assets/img/moon_stars_polarstar.bmp") {
		float randY = float(rand() % (GameDefs::WindowHeight / 3));
		float randX = float(rand() % GameDefs::WindowWidth);

		m_sprite->Draw_Dst(randX, randY);
		m_sprite->Draw_Src(0, 0, 5, 5);
		m_sprite->Draw_Siz(5, 5);
	}

	~Star() {
		SDL_free(this->m_sprite);
	}

	void Update(double dt) override {
		this->getSprite()->Offset_X(-speed * dt);
		if (this->getSprite()->get_X() < -5.0f) {
			this->getSprite()->Draw_Dst(320.0f+5.0f, float(rand() % 200));
		}
	}

	void Render() override {
		m_sprite->Render();
	}

	Sprite *getSprite() {
		return this->m_sprite;
	}

	void setSpeed(float num, float size) {
		speed = num;
		this->getSprite()->Draw_Siz(size,size);
	}

private:
	float speed = 0.0f;
};

#endif