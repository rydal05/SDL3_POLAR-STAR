#include "Managers/BackgroundManager.h"
#include "GameDefs.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <cmath>
#include <iostream>

void bgManager::moonSceneInit() { // TODO: include moon movement and stars rendering
	float width = 640.0f;
	float l1h = 63 * GameDefs::ScaleFactor;
	float l2h = 94 * GameDefs::ScaleFactor;
	float l3h = 117 * GameDefs::ScaleFactor;
	float l4h = 151 * GameDefs::ScaleFactor;

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

	moon.push_back(std::move(layer4_c));
	moon.push_back(std::move(layer4));
	moon.push_back(std::move(layer3_c));
	moon.push_back(std::move(layer3));
	moon.push_back(std::move(layer2_c));
	moon.push_back(std::move(layer2));
	moon.push_back(std::move(layer1_c));
	moon.push_back(std::move(layer1));
}

void bgManager::moonSceneUpdate(double dt) {
	if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;
	for (size_t i = 0; i < moon.size(); i++) {
		moon[i]->m_dst.x -= moon_speeds[i] * dt;

		if (moon[i]->m_dst.x <= -640.0f) moon[i]->m_dst.x += (640.0f * 2.0f);
	}
}

void bgManager::moonSceneRender() {

	for (size_t i = 0; i < moon.size(); i++) {
		moon[i]->Render();
	}
}

// void bgManager::updateMoonPos(double dt) {
// 	float SPEED = 2.0f;
// 	float t = dt * SPEED;

// 	float x = 250.0f * std::sin(t);
// 	float y = 150.0f * std::sin(t) * std::cos(t);

// }