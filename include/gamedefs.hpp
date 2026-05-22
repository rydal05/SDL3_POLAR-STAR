#ifndef GAMEDEFS_H
#define GAMEDEFS_H
#include <SDL3/SDL.h>

#define PLR_SPEED 0.25f
#define PLR_SPRITE_SIZE 64
#define SCALE 2
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BUL_SPD 0.5f
#define FIRE_RATE 1.5f

typedef enum {
	GAME,
	START,
	OVER
} gameMode;

inline SDL_Window *window = nullptr;
inline SDL_Renderer *renderer = nullptr;
inline gameMode mode = START;

#endif
