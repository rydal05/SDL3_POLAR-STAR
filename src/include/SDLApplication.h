#ifndef SDLAPP_H
#define SDLAPP_H

#include <SDL3/SDL.h>
#include <GameDefs.h>

class SDLApplication {
public:
	SDLApplication(const char *title, int w, int h) {
		SDL_SetAppMetadata("TEXT TEXT LALALALLALA", "Version Very Very Friend 0.0.1", "com.cantisresort.polarstar");

		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
			success = false;
		}
		if (!SDL_Init(SDL_INIT_GAMEPAD)) {
			SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
			success = false;
		}

		// make the window
		if (!SDL_CreateWindowAndRenderer("POLAR STAR", w * 2, h * 2, SDL_WINDOW_OPENGL, &g_window, &g_renderer)) {
			SDL_Log("Failed to create window and/or renderer: %s", SDL_GetError());
			success = false;
		}

		SDL_SetRenderLogicalPresentation(g_renderer, w, h, SDL_LOGICAL_PRESENTATION_LETTERBOX);
	}

private:
	bool success = true;
};

#endif