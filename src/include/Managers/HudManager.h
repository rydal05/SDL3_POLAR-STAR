#ifndef HUD_MANAGER_H
#define HUD_MANAGER_H

#include "GameDefs.h"
#include "Sprite.h"

#include <SDL3/SDL.h>
#include <memory>
#include <mutex>
#include <vector>

class Hud {
public:
	static Hud &getInstance();

	void HudUpdate();

	void HudRender() {
		for (size_t i = 0; i < gameplayElements.size(); i++) {
			gameplayElements[i]->Render();
		}
	}

	void hudStateManager();

	void makeTranslucent() {
		if (!visible) return;
		for (size_t i = 0; i < gameplayElements.size(); i++) {
			SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), 128);
		}
		visible = false;
	}

	void makeOpaque() {
		if (visible) return;
		for (size_t i = 0; i < gameplayElements.size(); i++) {
			SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), 255);
		}
		visible = true;
	}

	void gameplayHudInit() {

		auto hp_lv_bg = std::make_unique<Sprite>("assets/img/stg_story_ui.bmp");
		hp_lv_bg->Draw_Src(0, 0, 64, 32);
		hp_lv_bg->Draw_Dst(0, 0);
		hp_lv_bg->Draw_Siz(64 * GameDefs::ScaleFactor, 32 * GameDefs::ScaleFactor);

		auto gunIcon = std::make_unique<Sprite>("assets/img/stg_story_ui.bmp");
		gunIcon->Draw_Src(0, 32, 16, 16);
		gunIcon->Draw_Dst(0, 0);
		gunIcon->Draw_Siz(16 * GameDefs::ScaleFactor, 16 * GameDefs::ScaleFactor);

		auto levelIcon = std::make_unique<Sprite>("assets/img/stg_story_ui.bmp");
		levelIcon->Draw_Src(8, 64, 8, 8);
		levelIcon->Draw_Dst(16 * GameDefs::ScaleFactor, 16 * GameDefs::ScaleFactor);
		levelIcon->Draw_Siz(8 * GameDefs::ScaleFactor, 8 * GameDefs::ScaleFactor);

		gameplayElements.push_back(std::move(hp_lv_bg));
		gameplayElements.push_back(std::move(gunIcon));
		gameplayElements.push_back(std::move(levelIcon));
	}

	void setTransparency(int trans_num) {
		for (size_t i = 0; i < gameplayElements.size(); i++) {
			SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), trans_num);
		}
	}

private:
	Hud();
	Hud(Hud const &);
	Hud operator=(Hud const &);

	static std::once_flag initInstanceFlag;
	static Hud *Hud_Instance;

	bool visible = true;

	std::vector<std::unique_ptr<Sprite>> gameplayElements;
};

#endif