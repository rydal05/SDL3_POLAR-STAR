// my awesome 2d game engine framework thing

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <vector>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define MOVEMENT_SPEED 250

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
	if (!SDL_CreateWindowAndRenderer("SDL3 Shmup", 640, 480, SDL_WINDOW_OPENGL, &window, &renderer)) {
		SDL_Log("Failed to create window and/or renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_SetRenderLogicalPresentation(renderer, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);

	SDL_Texture *texture = NULL;
	SDL_Surface *surface = NULL;

	char *png_path = NULL;

	SDL_asprintf(&png_path, "%s/asset/img/ship.bmp", SDL_GetBasePath());
	surface = SDL_LoadBMP(png_path);

	int texture_width = surface->w;
	int texture_height = surface->h;
	if (!surface) {
		SDL_Log("Failed to load bitmap: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_free(png_path);

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_DestroySurface(surface);

	SDL_FRect dst_rect;
	dst_rect.h = 64;
	dst_rect.x = 64;
	dst_rect.w = 64;
	dst_rect.y = 64;
	// end to above
	SDL_Event event;
	bool running = true;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double dt = 0;

	// game loop begins
	while (running) {
		LAST = NOW; // deltatime calculations
		NOW = SDL_GetPerformanceCounter();
		dt = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
		dt *= 0.001; // convert ms -> s

		while (SDL_PollEvent(&event)) { // event handler
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.scancode == SDLK_ESCAPE) {
					running = false;
				}
			}
		}

		// update & run simulations

		const bool *keys = SDL_GetKeyboardState(NULL);

		if (keys[SDL_SCANCODE_UP]) dst_rect.y -= MOVEMENT_SPEED * dt;
		if (keys[SDL_SCANCODE_DOWN]) dst_rect.y += MOVEMENT_SPEED * dt;
		if (keys[SDL_SCANCODE_LEFT]) dst_rect.x -= MOVEMENT_SPEED * dt;
		if (keys[SDL_SCANCODE_RIGHT]) dst_rect.x += MOVEMENT_SPEED * dt; // TODO: Implement gamepad movement

		_draw();
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