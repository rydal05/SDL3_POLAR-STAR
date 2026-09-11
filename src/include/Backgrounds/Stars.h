#ifndef STARS_H
#define STARS_H

#include "GameDefs.h"
#include "superclasses/Entity.h"
#include "superclasses/Sprite.h"
#include <memory> // TODO: probably should also be made singleton
#include <vector>

// TODO: see comment made in clouds.h

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
		SDL_free(m_sprite);
	}

	void Update(double dt) override {
		this->getSprite()->Offset_X(-speed * dt);
		if (this->getSprite()->get_X() < -5.0f) {
			this->getSprite()->Draw_Dst(320.0f + 5.0f, float(rand() % 200));
		}
	}

	void Render() override {
		m_sprite->Render();
	}

	void setSpeed(float num, float size) {
		speed = num;
		this->getSprite()->Draw_Siz(size, size);
	}

private:
	float speed = 0.0f;
};

class Stars {
public:
	Stars(int quantity) {
		starsBG.reserve(quantity);

		for (size_t i = 0; i < quantity; i++) {
			auto star = std::make_unique<Star>();

			int type = rand() % 4;

			star->setSpeed(star_speeds[type], star_sizes[type]);
			starsBG.push_back(std::move(star));
			// SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
		}
	}
	~Stars() {
		starsBG.clear();
	};

	void Update(double dt) {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->Update(dt);
		}
	}
	void Render() {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->Render();
		}
	}

private:
	float maxSpeed = 1.0f;
	std::vector<float> star_speeds = {0.01f * maxSpeed, 0.02f * maxSpeed, 0.03f * maxSpeed, 0.05f * maxSpeed};
	std::vector<float> star_sizes = {2.0f, 3.0f, 4.0f, 5.0f};
	std::vector<std::unique_ptr<Star>> starsBG;
};

#endif