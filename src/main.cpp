// my awesome 2d game engine framework thing

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <SDL3/SDL_scancode.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

#include "ResourceManager.hpp"
#include "Sprite.hpp"
#include "bgManager.hpp"

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

static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;
static gameMode mode = START;

void _draw();
void _update();
void _init();

bgManager *bgManager::instancePtr = nullptr;
std::mutex bgManager::mtx;

int main(int argc, char *argv[]) {
	// setup
	SDL_SetAppMetadata("TEXT TEXT LALALALLALA", "Version Very Very Friend 0.0.1", "com.cantisresort.polarstar");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}
	if (!SDL_Init(SDL_INIT_GAMEPAD)) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	// make the window
	if (!SDL_CreateWindowAndRenderer("POLAR STAR", WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2, SDL_WINDOW_OPENGL, &window, &renderer)) {
		SDL_Log("Failed to create window and/or renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_SetRenderLogicalPresentation(renderer, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);

	SDL_Event event;
	bool running = true;
	Uint64 LAST = SDL_GetPerformanceCounter();
	Uint64 NOW = LAST;
	double dt = 0;
	// like all of this needs to be moved over to sprite factories and abstracted spaces eventually but not now
	Sprite player(renderer, "asset/img/stg_story.bmp");
	player.Draw_Src(0, 0, 16, 16);
	player.Draw_Dst(640 / 2, 480 / 2, 16 * SCALE, 16 * SCALE);
	Sprite bul(renderer, "asset/img/stg_story.bmp");
	bul.Draw_Src(64, 0, 16, 16);
	bul.Draw_Dst(0, 0, 16 * SCALE, 16 * SCALE);

	Sprite HPLV(renderer, "asset/img/stg_story_ui.bmp");
	HPLV.Draw_Src(0, 0, 64, 32);
	HPLV.Draw_Dst(0, 0, 64 * SCALE, 32 * SCALE);

	Sprite gunIcon(renderer, "asset/img/stg_story_ui.bmp");
	gunIcon.Draw_Src(0, 32, 16, 16);
	gunIcon.Draw_Dst(0, 0, 16 * SCALE, 16 * SCALE);

	Sprite levelIcon(renderer, "asset/img/stg_story_ui.bmp");
	levelIcon.Draw_Src(8, 64, 8, 8);
	levelIcon.Draw_Dst(16 * SCALE, 16 * SCALE, 8 * SCALE, 8 * SCALE);
	bool wait = false;
	float curWait = FIRE_RATE;

	bgManager *backgroundManager = bgManager::getInstance();
	backgroundManager->passRenderer(renderer);
	backgroundManager->moonSceneInit();

	while (running) {
		NOW = SDL_GetPerformanceCounter();
		dt = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
		LAST = NOW; // deltatime calculations
		const bool *state = SDL_GetKeyboardState(NULL);

		while (SDL_PollEvent(&event)) { // event handler
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
					running = false;
				}
			}
		}
		// player input and things like that
		if (state[SDL_SCANCODE_UP]) {
			player.m_dst.y -= (float)(PLR_SPEED * dt);
		}
		if (state[SDL_SCANCODE_LEFT]) {
			player.m_dst.x -= (float)(PLR_SPEED * dt);
		}
		if (state[SDL_SCANCODE_DOWN]) {
			player.m_dst.y += (float)(PLR_SPEED * dt);
		}
		if (state[SDL_SCANCODE_RIGHT]) {
			player.m_dst.x += (float)(PLR_SPEED * dt);
		}
		if (!wait) {
			if (state[SDL_SCANCODE_X]) {
				bul.m_dst.x = player.m_dst.x;
				bul.m_dst.y = player.m_dst.y;
				wait = true;
			}
		}
		if (wait) {
			curWait -= 0.01f * dt;
			if (curWait < 0.0f) {
				curWait = FIRE_RATE;
				wait = false;
			}
		}
		if (player.m_dst.y > 448) player.m_dst.y = 448;
		if (player.m_dst.y < 64) player.m_dst.y = 64; // bounds
		if (player.m_dst.x < 0) player.m_dst.x = 0;
		if (player.m_dst.x > 608) player.m_dst.x = 608;
		// update & run simulations
		player.Update(dt);
		backgroundManager->moonSceneUpdate(dt);
		// render everything that occured within the frame
		// wayland requires that something must be drawn to the screen in order for the window to actually exist i spent 2 hours figuring this out
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
		SDL_RenderClear(renderer);									 // clear canvas

		// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

		bul.m_dst.x += BUL_SPD * dt;

		backgroundManager->moonSceneRender();

		// player and enemies and things like that
		player.Render();
		bul.Render();
		// hud things and whatever else that should be drawn over the player or maybe we swap it i really dont know atm i cant lie
		HPLV.Render();
		gunIcon.Render();
		levelIcon.Render();

		SDL_RenderPresent(renderer); // put it all together now
	}

	// cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void _draw() {
	// render everything that occured within the frame
	// wayland requires that something must be drawn to the screen in order for the window to actually exist i spent 2 hours figuring this out
	// SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
	// SDL_RenderClear(renderer);									 // clear canvas

	// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);
	//
	// SDL_RenderPresent(renderer);
}

void _update() {
}

void startgame() {
	// set game's mode
	mode = GAME;
	// init character info
	struct player {
		int xpos = 0;
		int ypos = 0;

	} playercharacter;
	// init stats
	// reset background stuff
	// reset bullets vector
	// reset enemies vector
	//
}
