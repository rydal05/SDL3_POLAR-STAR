#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <iostream>

#include "Backgrounds/Star.h"
#include "GameDefs.h"
#include "Managers/BackgroundManager.h"

#include "Backgrounds/Clouds.h"
#include "Backgrounds/Moon.h"
#include "Backgrounds/Stars.h"

BG::BG() {
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
	starsManager = new Stars(32);

	moonManager = new Moon();

	cloudManager = new Clouds();
}

void BG::moonSceneUpdate(double dt) {
	if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;

	starsManager->Update(dt);

	moonManager->Update(dt); //needs to dynamically react to whatever stage is defined in gamedefs or something like that but probably afteri  actually get enemies and bullets working and all that 

	cloudManager->Update(dt);
}

void BG::moonSceneRender() { //convert to function pointers that bundle together update + render for environments for easier implementation and switching
	starsManager->Render();

	moonManager->Render();

	cloudManager->Render();
}