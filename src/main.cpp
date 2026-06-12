// my awesome 2d game engine framework thing
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <SDL3/SDL_scancode.h>
#include <math.h>
#include <stdio.h>

#include "HudManager.hpp"
#include "SDLApplication.hpp"
#include "bgManager.hpp"
#include "bullets.hpp"
#include "gamedefs.hpp"
#include "player.hpp"

void _draw();
void _update();
void _init();
void _framesetup();

Player player;
Bullet bul;
bgManager *backgroundManager = nullptr;
HudManager *hudMgr = nullptr;
double dt = 0.0;
bool paused = false;

bgManager *bgManager::instancePtr = nullptr;
std::mutex bgManager::mtx;

HudManager *HudManager::instancePtr = nullptr;
std::mutex HudManager::mtx;

int main(int argc, char *argv[]) {
	// setup

	SDLApplication app("POLAR STAR", 640, 480);
	const double targetFrameMs = 1000.0 / 60.0;

	SDL_Event event;
	bool running = true;
	Uint64 LAST = SDL_GetPerformanceCounter();
	// like all of this needs to be moved over to sprite factories and abstracted spaces eventually but not now

	backgroundManager = bgManager::getInstance();
	backgroundManager->moonSceneInit();

	hudMgr = HudManager::getInstance();
	hudMgr->gameplayHudInit();

	while (running) {
		const Uint64 frameStart = SDL_GetPerformanceCounter();
		const Uint64 now = frameStart;
		dt = (double)((now - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
		LAST = now; // deltatime calculations
		SDL_GetKeyboardState(NULL);

		while (SDL_PollEvent(&event)) { // event handler
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
					running = false;
				}
				if (event.key.scancode == SDL_SCANCODE_P) {
					paused = !paused;
				}
			}
		}

		if (paused) goto renderPresent;

		/*
			Bounds Checking
		*/
		_update();
		// update & run simulations
		// hudMgr->HudUpdate();
		//  render everything that occured within the frame
		//  wayland requires that something must be drawn to the screen in order for the window to actually exist i spent 2 hours figuring this out

		_framesetup();

	// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

	// gotolabel to implement pausing
	renderPresent:
		_draw();

		const Uint64 frameEnd = SDL_GetPerformanceCounter();
		const double frameMs = (double)((frameEnd - frameStart) * 1000 / (double)SDL_GetPerformanceFrequency());
		if (frameMs < targetFrameMs) {
			SDL_Delay((Uint32)(targetFrameMs - frameMs));
		}
	}

	// cleanup
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();

	return 0;
}

void _framesetup() {
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
	SDL_RenderClear(g_renderer);								   // clear canvas
}

void _draw() {
	if (player.m_dst.y < 64) {
		hudMgr->makeTranslucent();
	} // bounds for when player is hidden behind UI elements

	if (player.m_dst.y > 64) {
		hudMgr->makeOpaque();
	} // bounds for when player isnt hidden behind ui elements

	backgroundManager->moonSceneRender();
	hudMgr->HudRender();

	// player and enemies and things like that
	player.Render();
	bul.Render();
	// hud things and whatever else that should be drawn over the player or maybe we swap it i really dont know atm i cant lie
	//		HPLV.Render();
	//		gunIcon.Render();
	//		levelIcon.Render();
	// render everything that occured within the frame
	// wayland requires that something must be drawn to the screen in order for the window to actually exist i spent 2 hours figuring this out
	// SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
	// SDL_RenderClear(renderer);									 // clear canvas

	// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);
	//
	// SDL_RenderPresent(renderer);

	SDL_RenderPresent(g_renderer); // put it all together now
}

void _update() {
	player.Update(dt, bul);
	bul.Update(dt);

	backgroundManager->moonSceneUpdate(dt);
}

void startgame() {
	// set game's mode
	mode = GAME;
	// init character info
	// playercharacter;
	// init stats
	// reset background stuff
	// reset bullets vector
	// reset enemies vector
	//
}
