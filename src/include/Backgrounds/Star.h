#ifndef STAR_H
#define STAR_H

#include "Entity.h"
#include "GameDefs.h"
#include "Sprite.h"
#include <memory>
#include <vector>

class Star : public Entity {
public:
	Star() {
		m_sprite = new Sprite("assets/img/moon_stars_polarstar.bmp");
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
		this->getSprite()->m_dst.x -= speed * dt;
		if (this->getSprite()->m_dst.x < 0.0f) {
			this->getSprite()->m_dst.x = GameDefs::WindowWidth;
			this->getSprite()->m_dst.y = float(rand() % 200);
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
	Sprite *m_sprite;
	float speed = 0.0f;
};

#endif