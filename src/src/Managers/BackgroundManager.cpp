#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <iostream>

#include "Backgrounds/Star.h"
#include "GameDefs.h"
#include "Managers/BackgroundManager.h"

#include "Backgrounds/Clouds.h"
#include "Backgrounds/Moon.h"
#include "Backgrounds/Star.h"

BG::BG() {
	starsManager = new Stars(32);

	moonManager = new Moon();

	cloudManager = new Clouds();
}

BG::BG(BG const &) {}

BG BG::operator=(BG const &rhs) {
	return *this;
}

BG &BG::getInstance() {
	static BG *BG_instance = new BG;
	return *BG_instance;
}

void BG::moonSceneInit() {
	
}

void BG::moonSceneUpdate(double dt) {
	if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;

	starsManager->Update(dt);
	
	moonManager->Update(dt);

	cloudManager->Update(dt);
}

void BG::moonSceneRender() {
	starsManager->Render();
	
	moonManager->Render();

	cloudManager->Render();
}