#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <SDL3/SDL_scancode.h>
#include <math.h>
#include <stdio.h>

#include "Managers/BackgroundManager.h"
#include "Managers/HudManager.h"
#include "Managers/QueueManager.h"
#include "Managers/SDLApplication.h"

#include "GameDefs.h"
#include "Players/ActorPlayer.h"

void _draw();
void _update(double deltaTime);
void _init();
void _framesetup();

int main(int argc, char *argv[]) {
	GameDefs::GAME_STATUS = GameDefs::GameMode::GAME;
	SDLApplication app("POLAR STAR", 640, 480);
	const double targetFrameMs = 1000.0 / 60.0; // TODO: change how framerate and settings are handled

	SDL_Event *event;
	bool running = true;
	Uint64 LAST = SDL_GetPerformanceCounter();

	BG::getInstance().moonSceneInit();
	Hud::getInstance().gameplayHudInit();

	double deltaTime = 0.0;
	ActorPlayer *player = new ActorPlayer();
	Queue::getInstance().insert_player(player); // TODO: make constructor automatically insert self into associated queue

	// joy stick assignemnt
	// int *count = nullptr;
	// if (*SDL_GetJoysticks(count) < 1) {
	// 	SDL_Log("NO JOYSTICKS LOCATED");
	// } else {
	// 	GameDefs::joystickPlayer1 = SDL_OpenJoystick(0);
	// 	SDL_Log("JOYSTICK DETECTED");
	// }

	int xDir = 0;
	int yDir = 0;

	while (running) {
		const Uint64 frameStart = SDL_GetPerformanceCounter(); // TODO: create timer singleton class that gets updated here | 7/3/2026
		const Uint64 now = frameStart;
		deltaTime = (double)((now - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
		LAST = now;
		SDL_GetKeyboardState(NULL);

		while (SDL_PollEvent(event)) {
			if (event->type == SDL_EVENT_QUIT) {
				running = false;
			} else if (event->type == SDL_EVENT_KEY_DOWN) {
				if (event->key.scancode == SDL_SCANCODE_ESCAPE) {
					running = false;
				}
				if (event->key.scancode == SDL_SCANCODE_P) {
					if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) {
						GameDefs::GAME_STATUS = GameDefs::GameMode::GAME;
					} else if (GameDefs::GAME_STATUS == GameDefs::GameMode::GAME) {
						GameDefs::GAME_STATUS = GameDefs::GameMode::PAUSED;
					}
				}
			}
		}

		_update(deltaTime);
		_framesetup();
		_draw();

		const Uint64 frameEnd = SDL_GetPerformanceCounter();
		const double frameMs = (double)((frameEnd - frameStart) * 1000 / (double)SDL_GetPerformanceFrequency());
		if (frameMs < targetFrameMs) {
			SDL_Delay((Uint32)(targetFrameMs - frameMs));
		}
	}

	SDL_DestroyRenderer(GameDefs::g_renderer);
	SDL_DestroyWindow(GameDefs::g_window);
	SDL_Quit();

	return 0;
}

void _framesetup() {
	SDL_SetRenderDrawColor(GameDefs::g_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(GameDefs::g_renderer);
}

void _draw() {
	BG::getInstance().moonSceneRender();
	Hud::getInstance().HudRender();

	Queue::getInstance().render_queue();

	SDL_RenderPresent(GameDefs::g_renderer);
}

void _update(double deltaTime) {
	if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;
	BG::getInstance().moonSceneUpdate(deltaTime);

	Queue::getInstance().update_queue(deltaTime);
}

void startgame() {
	// TODO: incorporate proper game startup (new player instantation, change gamemode, etc)
}
