#ifndef STARS_H
#define STARS_H

#include "Entity.h"
#include "GameDefs.h"
#include "Sprite.h"
#include <memory>
#include <vector>

class Stars : public Entity {
public:
	Stars(int quantity) {
		for (size_t i = 0; i < quantity; i++) {
			auto star = std::make_unique<Sprite>("assets/img/moon_stars_polarstar.bmp");
			float randY = float(rand() % (GameDefs::WindowHeight / 3));
			float randX = float(rand() % GameDefs::WindowWidth);

			star->Draw_Src(0, 0, 5, 5);
			star->Draw_Dst(randX, randY);
			star->Draw_Siz(5, 5);

			starsBG.push_back(std::move(star));
			// SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
		}
	}
	~Stars() {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i].reset();
			// SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
		}
	};

	void Update(double dt) override {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->m_dst.x -= 0.1f * dt;
			if (starsBG[i]->m_dst.x < 0.0f) {
				starsBG[i]->m_dst.x = GameDefs::WindowWidth;
				starsBG[i]->m_dst.y = float(rand() % 200);
			}
		}
	}
	void Render() override {
		for (size_t i = 0; i < starsBG.size(); i++) {
			starsBG[i]->Render();
		}
	}

private:
	float speed;
	std::vector<std::unique_ptr<Sprite>> starsBG;
};

#endif