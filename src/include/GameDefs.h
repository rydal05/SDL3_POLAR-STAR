#ifndef GAMEDEFS_H
#define GAMEDEFS_H

#include <SDL3/SDL.h>

namespace GameDefs {
	constexpr float PlayerSpeed = 0.25f;
	constexpr int PlayerSpriteSize = 64;
	constexpr int ScaleFactor = 2;
	
	constexpr int WindowWidth = 640;
	constexpr int WindowHeight = 480;

	enum class GameMode {
		GAME,
		START,
		OVER,
		PAUSED,
		SETTINGS
	};

	inline SDL_Window *g_window = nullptr;
	inline SDL_Renderer *g_renderer = nullptr;

	inline GameMode GAME_STATUS;
}

#endif