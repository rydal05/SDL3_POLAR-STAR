#ifndef BACKGROUND_MANANGER_H
#define BACKGROUND_MANANGER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <mutex>
#include <vector>

#include "GameDefs.h"
#include "Managers/ResourceManager.h"
#include "Sprite.h"

#include "Backgrounds/Clouds.h"
#include "Backgrounds/Moon.h"
#include "Backgrounds/Star.h"

class BG {

public:
	static BG &getInstance();

	void moonSceneInit();
	void moonSceneUpdate(double dt);
	void moonSceneRender();
	void updateMoon(double dt);
	void updateStars(double dt);

	void renderScene();
	void switchScene();

private:
	BG();
	BG(BG const &);
	BG operator=(BG const &);

	bool direction = true;

	Stars *starsManager = NULL;
	Moon *moonManager = NULL;
	Clouds *cloudManager = NULL;
};

#endif