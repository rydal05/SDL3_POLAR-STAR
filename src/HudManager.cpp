#include "HudManager.hpp"
#include "gamedefs.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>

void HudManager::gameplayHudInit() {

	auto hp_lv_bg = std::make_unique<Sprite>("asset/img/stg_story_ui.bmp");
	hp_lv_bg->Draw_Src(0, 0, 64, 32);
	hp_lv_bg->Draw_Dst(0, 0, 64 * SCALE, 32 * SCALE);

	auto gunIcon = std::make_unique<Sprite>("asset/img/stg_story_ui.bmp");
	gunIcon->Draw_Src(0, 32, 16, 16);
	gunIcon->Draw_Dst(0, 0, 16 * SCALE, 16 * SCALE);

	auto levelIcon = std::make_unique<Sprite>("asset/img/stg_story_ui.bmp");
	levelIcon->Draw_Src(8, 64, 8, 8);
	levelIcon->Draw_Dst(16 * SCALE, 16 * SCALE, 8 * SCALE, 8 * SCALE);

	gameplayElements.push_back(std::move(hp_lv_bg));
	gameplayElements.push_back(std::move(gunIcon));
	gameplayElements.push_back(std::move(levelIcon));
}

void HudManager::HudUpdate() {
}

void HudManager::HudRender() {
	for (size_t i = 0; i < gameplayElements.size(); i++) {
		gameplayElements[i]->Render();
	}
}

void HudManager::makeTranslucent() {
	if (!visible) return;
	for (size_t i = 0; i < gameplayElements.size(); i++) {
		SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), 128);
	}
	visible = false;
}

void HudManager::makeOpaque() {
	if (visible) return;
	for (size_t i = 0; i < gameplayElements.size(); i++) {
		SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), 255);
	}
	visible = true;
}
