#ifndef BACKGROUND_MANANGER_H
#define BACKGROUND_MANANGER_H

#include "Managers/ResourceManager.h"
#include "Sprite.h"

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

	void renderScene();
	void switchScene();

private:
	BG();
	BG(BG const &);
	BG operator=(BG const &);

	std::vector<std::unique_ptr<Sprite>> cloudsBG;
	std::vector<float> moon_speeds = {0.1f,0.2f, 0.3f, 0.5f};
	// std::vector<float> moon_speeds = {0.1f, 0.1f, 0.2f, 0.2f, 0.3f, 0.3f, 0.5f, 0.5f};

	Sprite *moon;
	bool direction;
	float x = 500.0f;
	float y = 0.0f;
};

#endif