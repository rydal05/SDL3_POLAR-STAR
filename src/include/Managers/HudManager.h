#ifndef HUD_MANAGER_H
#define HUD_MANAGER_H

#include "GameDefs.h"
#include "Sprite.h"

#include <SDL3/SDL.h>
#include <memory>
#include <mutex>
#include <vector>

#include "Hud/Hud_HP.h"
#include "Hud/Hud_Level.h"

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
			// SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), 128);
		}
		visible = false;
	}

	void makeOpaque() {
		if (visible) return;
		for (size_t i = 0; i < gameplayElements.size(); i++) {
			// SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), 255);
		}
		visible = true;
	}

	void gameplayHudInit() {

		HP *healthInfo = new HP();
		Level *levelInfo = new Level();

		gameplayElements.push_back(healthInfo);
		gameplayElements.push_back(levelInfo);
	}

	void setTransparency(int trans_num) {
		for (size_t i = 0; i < gameplayElements.size(); i++) {
			// SDL_SetTextureAlphaMod(gameplayElements[i]->GetTexture(), trans_num);
		}
	}

private:
	Hud();
	Hud(Hud const &);
	Hud operator=(Hud const &);

	static std::once_flag initInstanceFlag;
	static Hud *Hud_Instance;

	bool visible = true;

	std::vector<Entity*> gameplayElements;
};

#endif