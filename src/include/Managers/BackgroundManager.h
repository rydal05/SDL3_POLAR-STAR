#ifndef BACKGROUND_MANANGER_H
#define BACKGROUND_MANANGER_H

#include "Managers/ResourceManager.h"
#include "Sprite.h"

#include "GameDefs.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <vector>

#include <mutex>

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

	Sprite *moon;
	bool direction = true;
	float x = 250.0f * GameDefs::ScaleFactor;
	float y = 0.0f;
};

#endif