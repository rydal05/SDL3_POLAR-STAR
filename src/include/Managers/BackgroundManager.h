#ifndef BACKGROUND_MANANGER_H
#define BACKGROUND_MANANGER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <mutex>
#include <vector>

#include "GameDefs.h"
#include "Managers/ResourceManager.h"
#include "superclasses/Sprite.h"

#include "Backgrounds/Clouds.h"
#include "Backgrounds/Moon.h"
#include "Backgrounds/Stars.h"

class BG {

public:
	static BG &getInstance();

	void moonSceneInit();

	void moonSceneUpdate(double dt);
	void moonSceneRender();

	void renderScene();

private:
	BG();
	BG(BG const &);
	BG operator=(BG const &);

	bool direction = true;

	Stars *starsManager{nullptr};
	Moon *moonManager{nullptr};
	Clouds *cloudManager{nullptr};

	enum backgroundTypes {
		SURFACE,
		MOON,
		CAVE,
		BLOOD_STAINED,
		LABRYINTH,
		BUSHLANDS,
		WATERWAY,
		OUTER_WALL,
		PLANTATION,

		STATS_SIZE,
	};
};

#endif