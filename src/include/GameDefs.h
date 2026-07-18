#ifndef GAMEDEFS_H
#define GAMEDEFS_H

#include <SDL3/SDL.h>

namespace GameDefs {
constexpr float PlayerSpeed = 0.25f;
constexpr float PlayerSpriteSize = 64.0f;
constexpr float ScaleFactor = 1.0f;

constexpr int WindowWidth = 320 * ScaleFactor;
constexpr int WindowHeight = 240 * ScaleFactor;

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
inline SDL_Joystick *joystick = nullptr;

constexpr int dead_zone = 8000;


} // namespace GameDefs

#endif