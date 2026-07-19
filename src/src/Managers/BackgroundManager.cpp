#include "Managers/BackgroundManager.h"
#include "GameDefs.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <cmath>
#include <cstdlib>
#include <iostream>

BG::BG() {}

BG::BG(BG const &) {}

BG BG::operator=(BG const &rhs) {
	return *this;
}

BG &BG::getInstance() {
	static BG *BG_instance = new BG;
	return *BG_instance;
}

void BG::moonSceneInit() {

	for (size_t i = 0; i < starsQuantity; i++) {
		auto star = std::make_unique<Sprite>("assets/img/moon_stars_polarstar.bmp");
		float randY = float(rand() % (GameDefs::WindowHeight / 3));
		float randX = float(rand() % GameDefs::WindowWidth);

		star->Draw_Src(0, 0, 5, 5);
		star->Draw_Dst(randX, randY);
		star->Draw_Siz(5, 5);

		starsBG.push_back(std::move(star));
		SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
	}

	moon = new Sprite("assets/img/moon_stars_polarstar.bmp");
	moon->Draw_Src(10.0f, 0.0f, 34.f, 34.f);
	// pos 10 0
	// size 34 x 34
	// moon->Draw_Dst(0.0f, 0.0f);
	moon->Draw_Siz(34.0f, 34.0f);

	
}

void BG::moonSceneUpdate(double dt) {
	if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;

	
	updateMoon(dt);
	updateStars(dt);
}

void BG::moonSceneRender() {
	for (size_t i = 0; i < starsBG.size(); i++) {
		starsBG[i]->Render();
	}

	

	moon->Render();
}

void BG::updateMoon(double dt) {
	// y = x whatever whatever function or reverse to accomplish what it is i want here

	float offsetX = 250.0f * GameDefs::ScaleFactor;
	float offsetY = 25.0f * GameDefs::ScaleFactor;

	float speed = .001f * dt;

	float UB = offsetX + 50.0f * GameDefs::ScaleFactor;
	float LB = offsetX - 50.0f * GameDefs::ScaleFactor;

	float stretchH = 10.0f;
	float strecthW = 5.0f;

	switch (direction) {
		case (true): {
			y = (stretchH * ((sin(x + offsetX)) / (strecthW))) + offsetY; //SINE WAVE FUNCTION
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

	moon->Draw_Dst(x, y);
}

void BG::updateStars(double dt) {
	for (size_t i = 0; i < starsBG.size(); i++) {
		starsBG[i]->m_dst.x -= 0.1f * dt;
		if (starsBG[i]->m_dst.x < 0.0f) {
			starsBG[i]->m_dst.x = GameDefs::WindowWidth;
			starsBG[i]->m_dst.y = float(rand() % 200);
		}

		// SDL_Log("Updating star %d", i);
	}
}