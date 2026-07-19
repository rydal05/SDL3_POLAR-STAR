#ifndef STARS_H
#define STARS_H

#include "Entity.h"
#include "GameDefs.h"
#include "Sprite.h"
#include "Star.h"
#include <memory>
#include <vector>

class Stars : public Entity {
public:
	Stars(int quantity) {
		for (size_t i = 0; i < quantity; i++) {
			auto star = std::make_unique<Star>();

            int type = rand() % 4;

			star->setSpeed(star_speeds[type], star_sizes[type]);
			starsBG.push_back(std::move(star));
			// SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
		}
	}
	~Stars() {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->~Star();
			starsBG[i].reset();
			// SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
		}
	};

	void Update(double dt) override {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->Update(dt);
		}
	}
	void Render() override {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->Render();
		}
	}

private:
	float maxSpeed = GameDefs::ScaleFactor;
	std::vector<float> star_speeds = {0.01f * maxSpeed, 0.02f * maxSpeed, 0.03f * maxSpeed, 0.05f * maxSpeed};
	std::vector<float> star_sizes = {2.0f, 3.0f, 4.0f, 5.0f};
	std::vector<std::unique_ptr<Star>> starsBG;
};

#endif