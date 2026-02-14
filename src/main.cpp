// my awesome 2d game engine framework thing

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

#include "ResourceManager.hpp"
#include "Sprite.hpp"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PLR_SPEED 0.25f

void _draw();
void _update();
void _init();

static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;

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
	if (!SDL_CreateWindowAndRenderer("POLAR STAR", 640, 480, SDL_WINDOW_OPENGL, &window, &renderer)) {
		SDL_Log("Failed to create window and/or renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_SetRenderLogicalPresentation(renderer, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);

	SDL_Event event;
	bool running = true;
	Uint64 LAST = SDL_GetPerformanceCounter();
	Uint64 NOW = LAST;
	double dt = 0;

	Sprite player(renderer, "asset/img/stg_story.bmp");
	player.Draw_Src(0, 0, 15, 15);
	player.Draw_Dst(64, 64, 32, 32);

	Sprite HPLV(renderer, "asset/img/stg_story_ui.bmp");
	HPLV.Draw_Src(0, 0, 63, 31);
	HPLV.Draw_Dst(0, 0, 64 * 2, 32 * 2);

	// game loop begins
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

		if (player.m_dst.y > 448) player.m_dst.y = 448;
		if (player.m_dst.y < 64) player.m_dst.y = 64;
		if (player.m_dst.x < 0) player.m_dst.x = 0;
		if (player.m_dst.x > 608) player.m_dst.x = 608;
		// update & run simulations
		// player.Update(dt);

		// render everything that occured within the frame
		// wayland requires that something must be drawn to the screen in order for the window to actually exist i spent 2 hours figuring this out
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
		SDL_RenderClear(renderer);									 // clear canvas

		// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

		player.Render(renderer);
		HPLV.Render(renderer);
		SDL_RenderPresent(renderer);
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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
	SDL_RenderClear(renderer);									 // clear canvas

	// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

	SDL_RenderPresent(renderer);
}

void _update() {
}

void _init() {
}
