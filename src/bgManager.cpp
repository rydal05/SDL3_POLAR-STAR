#include "bgManager.hpp"
#include "gamedefs.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <iostream>

void bgManager::moonSceneInit() {
	auto bg1 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg1->Draw_Src(0, 0, 640 / 2, 176 / 2);
	bg1->Draw_Dst(0, WINDOW_HEIGHT - 176, 640, 176);

	auto bg2 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg2->Draw_Src(640 / 2, 0, 640 / 2, 192 / 2);
	bg2->Draw_Dst(0, WINDOW_HEIGHT - 192, 640, 192);

	auto bg3 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg3->Draw_Src(640 / 2, 192 / 2, 640 / 2, 288 / 2);
	bg3->Draw_Dst(0, WINDOW_HEIGHT - 288, 640, 288); // game loop begins

	auto bg4 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg4->Draw_Src(0, 176 / 2, 640 / 2, 304 / 2);
	bg4->Draw_Dst(0, WINDOW_HEIGHT - 304, 640, 192);

	auto bg12 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg12->Draw_Src(0, 0, 640 / 2, 176 / 2);
	bg12->Draw_Dst(-640, WINDOW_HEIGHT - 176, 640, 176);

	auto bg22 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg22->Draw_Src(640 / 2, 0, 640 / 2, 192 / 2);
	bg22->Draw_Dst(-640, WINDOW_HEIGHT - 192, 640, 192);

	auto bg32 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg32->Draw_Src(640 / 2, 192 / 2, 640 / 2, 288 / 2);
	bg32->Draw_Dst(-640, WINDOW_HEIGHT - 288, 640, 288);

	auto bg42 = std::make_unique<Sprite>(m_renderer, "asset/img/stg_story_bgs.bmp");
	bg42->Draw_Src(0, 176 / 2, 640 / 2, 304 / 2);
	bg42->Draw_Dst(-640, WINDOW_HEIGHT - 304, 640, 192);

	moon.push_back(std::move(bg4));
	moon.push_back(std::move(bg3));
	moon.push_back(std::move(bg2));
	moon.push_back(std::move(bg1));

	moon_paral.push_back(std::move(bg42));
	moon_paral.push_back(std::move(bg32));
	moon_paral.push_back(std::move(bg22));
	moon_paral.push_back(std::move(bg12));
}

void bgManager::moonSceneUpdate(double dt) {
	for (size_t i = 0; i < moon.size(); i++) {
		moon[i]->m_dst.x += moon_speeds[i] * dt;

		moon_paral[i]->m_dst.x = moon[i]->m_dst.x + 640.0f;

		if (moon[i]->m_dst.x <= -640.0f) moon[i]->m_dst.x = 0.0f;
	}
}

void bgManager::moonSceneRender() {

	for (size_t i = 0; i < moon.size(); i++) {
		moon[i]->Render();
		moon_paral[i]->Render();
	}
}
