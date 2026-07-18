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
	float width = 640.0f;
	float l1h = 63 * GameDefs::ScaleFactor;
	float l2h = 94 * GameDefs::ScaleFactor;
	float l3h = 117 * GameDefs::ScaleFactor;
	float l4h = 151 * GameDefs::ScaleFactor;

	for (size_t i = 0; i < starsQuantity; i++) {
		auto star = std::make_unique<Sprite>("assets/img/moon_stars_polarstar.bmp");
		float randY = (int)(rand() % 151);
		float randX = (int)(rand() % 640);

		star->Draw_Src(0, 0, 5, 5);
		star->Draw_Dst(x, y);
		star->Draw_Siz(5 * GameDefs::ScaleFactor, 5 * GameDefs::ScaleFactor);

		starsBG.push_back(std::move(star));
	}

	moon = new Sprite("assets/img/moon_stars_polarstar.bmp");
	moon->Draw_Src(10.0f, 0.0f, 34.f, 34.f);
	// pos 10 0
	// size 34 x 34
	// moon->Draw_Dst(0.0f, 0.0f);
	moon->Draw_Siz(34.0f * GameDefs::ScaleFactor, 34.0f * GameDefs::ScaleFactor);

	auto layer1 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer1->Draw_Src(0.0f, 0.0f, 320.0f, l1h / GameDefs::ScaleFactor);
	layer1->Draw_Dst(0.0f, GameDefs::WindowHeight - l1h);
	layer1->Draw_Siz(width, l1h);

	auto layer2 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer2->Draw_Src(0.0f, 63.0f, 320.0f, l2h / GameDefs::ScaleFactor);
	layer2->Draw_Dst(0.0f, GameDefs::WindowHeight - l2h);
	layer2->Draw_Siz(width, l2h);

	auto layer3 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer3->Draw_Src(0.0f, 157.0f, 320.0f, l3h / GameDefs::ScaleFactor);
	layer3->Draw_Dst(0.0f, GameDefs::WindowHeight - l3h);
	layer3->Draw_Siz(width, l3h);

	auto layer4 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer4->Draw_Src(0.0f, 274.0f, 320.0f, l4h / GameDefs::ScaleFactor);
	layer4->Draw_Dst(0.0f, GameDefs::WindowHeight - l4h);
	layer4->Draw_Siz(width, l4h);

	auto layer1_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer1_c->Draw_Src(0.0f, 0.0f, 320.0f, l1h / GameDefs::ScaleFactor);
	layer1_c->Draw_Dst(640.0f, GameDefs::WindowHeight - l1h);
	layer1_c->Draw_Siz(width, l1h);

	auto layer2_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer2_c->Draw_Src(0.0f, 63.0f, 320.0f, l2h / GameDefs::ScaleFactor);
	layer2_c->Draw_Dst(640.0f, GameDefs::WindowHeight - l2h);
	layer2_c->Draw_Siz(width, l2h);

	auto layer3_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer3_c->Draw_Src(0.0f, 157.0f, 320.0f, l3h / GameDefs::ScaleFactor);
	layer3_c->Draw_Dst(640.0f, GameDefs::WindowHeight - l3h);
	layer3_c->Draw_Siz(width, l3h);

	auto layer4_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer4_c->Draw_Src(0.0f, 274.0f, 320.0f, l4h / GameDefs::ScaleFactor);
	layer4_c->Draw_Dst(640.0f, GameDefs::WindowHeight - l4h);
	layer4_c->Draw_Siz(width, l4h);

	cloudsBG.push_back(std::move(layer4_c));
	cloudsBG.push_back(std::move(layer4));
	cloudsBG.push_back(std::move(layer3_c));
	cloudsBG.push_back(std::move(layer3));
	cloudsBG.push_back(std::move(layer2_c));
	cloudsBG.push_back(std::move(layer2));
	cloudsBG.push_back(std::move(layer1_c));
	cloudsBG.push_back(std::move(layer1));
}

void BG::moonSceneUpdate(double dt) {
	if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;
	for (size_t i = 0; i < cloudsBG.size(); i++) {
		int x = i / 2;
		cloudsBG[i]->m_dst.x -= moon_speeds[x] * dt;

		if (cloudsBG[i]->m_dst.x <= -640.0f) cloudsBG[i]->m_dst.x += (640.0f * 2.0f);
	}
	updateMoon(dt);
}

void BG::moonSceneRender() {
	for (size_t i = 0; i < cloudsBG.size(); i++) {
		cloudsBG[i]->Render();
	}

	for (size_t i = 0; i < starsBG.size(); i++) {
		starsBG[i]->Render();
	}

	moon->Render();
}

void BG::updateMoon(double dt) {
	// y = x whatever whatever function or reverse to accomplish what it is i want here

	float offsetX = 500.0f;
	float offsetY = 50.0f;

	float speed = .001f * dt;

	float UB = offsetX + 50.0f;
	float LB = offsetX - 50.0f;

	float stretchH = 10.0f;
	float strecthW = 5.0f;

	switch (direction) {
		case (true): {
			y = (stretchH * ((sin(x + offsetX)) / (strecthW))) + offsetY;
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

	SDL_Log("XY POS %.2f %.2f", x, y);

	moon->Draw_Dst(x, y);
}

void BG::updateStars(double dt) {
	for(size_t i = 0; i < starsBG.size(); i++){
		
	}
}