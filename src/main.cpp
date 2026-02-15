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

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PLR_SPEED 0.25f
#define PLR_SPRITE_SIZE 32
#define SCALE 2
#define BUL_SPD 0.5f
#define FIRE_RATE 1.5f

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
	player.Draw_Src(0, 0, 16, 16);
	player.Draw_Dst(640 / 2, 480 / 2, PLR_SPRITE_SIZE, PLR_SPRITE_SIZE);

	Sprite HPLV(renderer, "asset/img/stg_story_ui.bmp");
	HPLV.Draw_Src(0, 0, 64, 32);
	HPLV.Draw_Dst(0, 0, 64 * SCALE, 32 * SCALE);

	Sprite gunIcon(renderer, "asset/img/stg_story_ui.bmp");
	gunIcon.Draw_Src(0, 32, 16, 16);
	gunIcon.Draw_Dst(0, 0, 16 * SCALE, 16 * SCALE);

	Sprite levelIcon(renderer, "asset/img/stg_story_ui.bmp");
	levelIcon.Draw_Src(8, 64, 8, 8);
	levelIcon.Draw_Dst(16 * SCALE, 16 * SCALE, 8 * SCALE, 8 * SCALE);

	Sprite bg1(renderer, "asset/img/stg_story_bgs.bmp");
	bg1.Draw_Src(0, 0, 640, 176);
	bg1.Draw_Dst(0, WINDOW_HEIGHT - 176, 640, 176);

	Sprite bg2(renderer, "asset/img/stg_story_bgs.bmp");
	bg2.Draw_Src(640, 0, 640, 192);
	bg2.Draw_Dst(0, WINDOW_HEIGHT - 192, 640, 192);

	Sprite bg4(renderer, "asset/img/stg_story_bgs.bmp");
	bg4.Draw_Src(0, 176, 640, 304);
	bg4.Draw_Dst(0, WINDOW_HEIGHT - 304, 640, 192);

	Sprite bg3(renderer, "asset/img/stg_story_bgs.bmp");
	bg3.Draw_Src(640, 192, 640, 288);
	bg3.Draw_Dst(0, WINDOW_HEIGHT - 288, 640, 288); // game loop begins

	Sprite bg12(renderer, "asset/img/stg_story_bgs.bmp");
	bg12.Draw_Src(0, 0, 640, 176);
	bg12.Draw_Dst(-640, WINDOW_HEIGHT - 176, 640, 176);

	Sprite bg22(renderer, "asset/img/stg_story_bgs.bmp");
	bg22.Draw_Src(640, 0, 640, 192);
	bg22.Draw_Dst(-640, WINDOW_HEIGHT - 192, 640, 192);

	Sprite bg32(renderer, "asset/img/stg_story_bgs.bmp");
	bg32.Draw_Src(640, 192, 640, 288);
	bg32.Draw_Dst(-640, WINDOW_HEIGHT - 288, 640, 288);

	Sprite bg42(renderer, "asset/img/stg_story_bgs.bmp");
	bg42.Draw_Src(0, 176, 640, 304);
	bg42.Draw_Dst(-640, WINDOW_HEIGHT - 304, 640, 192);

	Sprite bul(renderer, "asset/img/stg_story.bmp");
	bul.Draw_Src(64, 0, 16, 16);
	bul.Draw_Dst(0, 0, 16 * SCALE, 16 * SCALE);

	float speed1 = 0.05f;
	float speed2 = 0.03f;
	float speed3 = 0.02f;
	float speed4 = 0.01f;

	bool wait = false;
	float curWait = FIRE_RATE;

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
		// player.Update(dt);
		bg1.m_dst.x += speed1 * dt;
		bg2.m_dst.x += speed2 * dt;
		bg3.m_dst.x += speed3 * dt;
		bg4.m_dst.x += speed4 * dt;
		bg12.m_dst.x = bg1.m_dst.x - 640.0f;
		bg22.m_dst.x = bg2.m_dst.x - 640.0f;
		bg32.m_dst.x = bg3.m_dst.x - 640.0f;
		bg42.m_dst.x = bg4.m_dst.x - 640.0f;

		if (bg1.m_dst.x >= 640.0f) bg1.m_dst.x = 0.0f;
		if (bg2.m_dst.x >= 640.0f) bg2.m_dst.x = 0.0f;
		if (bg3.m_dst.x >= 640.0f) bg3.m_dst.x = 0.0f;
		if (bg4.m_dst.x >= 640.0f) bg4.m_dst.x = 0.0f;

		// render everything that occured within the frame
		// wayland requires that something must be drawn to the screen in order for the window to actually exist i spent 2 hours figuring this out
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
		SDL_RenderClear(renderer);									 // clear canvas

		// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

		bul.m_dst.x += BUL_SPD * dt;

		// background things
		bg4.Render(renderer);
		bg42.Render(renderer);
		bg3.Render(renderer);
		bg32.Render(renderer);
		bg2.Render(renderer);
		bg22.Render(renderer);
		bg1.Render(renderer);
		bg12.Render(renderer);

		// player and enemies and things like that
		player.Render(renderer);
		bul.Render(renderer);
		// hud things and whatever else that should be drawn over the player or maybe we swap it i really dont know atm i cant lie
		HPLV.Render(renderer);
		gunIcon.Render(renderer);
		levelIcon.Render(renderer);

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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // bg color
	SDL_RenderClear(renderer);									 // clear canvas

	// SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

	SDL_RenderPresent(renderer);
}

void _update() {
}

void _init() {
}
