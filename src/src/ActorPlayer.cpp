#include "ActorPlayer.h"
#include "Managers/HudManager.h"

ActorPlayer::ActorPlayer() : m_sprite("assets/img/stg_story.bmp") {
	m_dst.x = GameDefs::WindowWidth / 2.0f;
	m_dst.y = GameDefs::WindowHeight / 2.0f;
	m_dst.w = 16;
	m_dst.h = 16;


	// ensure parity with sprite

	// SDL_Log("[ACTORPLAYER] update finished");

	
	m_sprite.Draw_Src(0, 0, 16, 16);
	m_sprite.Draw_Dst(m_dst.x, m_dst.y);
	m_sprite.Draw_Siz(m_dst.w, m_dst.h);

	m_gamepad = nullptr;

	SDL_Log("[ACTORPLAYER] successful instantiation");
}

void ActorPlayer::update(double dt) {
	const bool *state = SDL_GetKeyboardState(nullptr);
	SDL_PumpEvents();
	movement(state, dt);
	collision(state);
	
	/*
	1. Handle inputs
	2. Handle external interactions (pickups, contact with bullets, border collisions, etc)
	3. Hud updates
	...
	n-1. Pair sprite to pos
	*/
}

void ActorPlayer::render() {
	if (m_dst.y < 64) {
		Hud::getInstance().makeTranslucent();
	} // bounds for when player is hidden behind UI elements
	
	if (m_dst.y > 64) {
		Hud::getInstance().makeOpaque();
	}
	
	m_sprite.m_dst = m_dst; // moved
	m_sprite.Render();
}

void ActorPlayer::move(float x, float y) { // not movement just explicit placement at a location
	m_dst.x += SPEED * x;
	m_dst.y += SPEED * y;
}

void ActorPlayer::movement(const bool *state, double dt) {
	if (GameDefs::joystick != NULL) {
		int total, i;
		total = SDL_GetNumJoystickHats(GameDefs::joystick);
		for (i = 0; i < total; i++) {
			const Uint8 hat = SDL_GetJoystickHat(GameDefs::joystick, i);

			if (hat & SDL_HAT_RIGHT || state[SDL_SCANCODE_RIGHT]) {
				m_dst.x += static_cast<float>(SPEED * dt);
			}
			if (hat & SDL_HAT_LEFT || state[SDL_SCANCODE_LEFT]) {
				m_dst.x -= static_cast<float>(SPEED * dt);
			}
			if (hat & SDL_HAT_DOWN || state[SDL_SCANCODE_DOWN]) {
				m_dst.y += static_cast<float>(SPEED * dt);
			}
			if (hat & SDL_HAT_UP || state[SDL_SCANCODE_UP]) {
				m_dst.y -= static_cast<float>(SPEED * dt);
			}
		}
	} else if (GameDefs::joystick == NULL) {
		if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
			m_dst.x += static_cast<float>(SPEED * dt);
			// SDL_Log("[ACTORPLAYER] Input received");
		}
		if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
			m_dst.x -= static_cast<float>(SPEED * dt);
			// SDL_Log("[ACTORPLAYER] Input received");
		}
		if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
			m_dst.y += static_cast<float>(SPEED * dt);
			// SDL_Log("[ACTORPLAYER] Input received");
		}
		if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
			m_dst.y -= static_cast<float>(SPEED * dt);
			// SDL_Log("[ACTORPLAYER] Input received");
		}
	}
}

void ActorPlayer::collision(const bool *state) {
	if (m_dst.y > GameDefs::WindowHeight-m_dst.h) m_dst.y = GameDefs::WindowHeight-m_dst.h;
	if (m_dst.x > GameDefs::WindowWidth-m_dst.w) m_dst.x = GameDefs::WindowWidth-m_dst.w;
	if (m_dst.y < 0.0f) m_dst.y = 0.0f;
	if (m_dst.x < 0.0f) m_dst.x = 0.0f;
}

void ActorPlayer::swapWeapon(const bool *state) {

}

void ActorPlayer::shoot(const bool *state) {

}