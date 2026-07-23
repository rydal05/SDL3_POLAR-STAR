#include "ActorPlayer.h"
#include "Managers/HudManager.h"

ActorPlayer::ActorPlayer() {

	// ensure parity with sprite

	// SDL_Log("[ACTORPLAYER] update finished");

	m_sprite->Draw_Src(0, 0, 16, 16); // TODO: refactor actorplayer to be base class instead nad purge the player class (it does literally nothing) so i can then build up the othercharacter classes and whatever
	m_sprite->Draw_Dst(320.0f / 2.0f, 240.0f / 2.0f);
	m_sprite->Draw_Siz(16.0f, 16.0f);
	m_gamepad = nullptr;

	// SDL_Log("[ACTORPLAYER] successful instantiation");
}

void ActorPlayer::Update(double dt) {
	const bool *state = SDL_GetKeyboardState(nullptr);
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

void ActorPlayer::Render() {
	if (m_sprite->m_dst.y < GameDefs::WindowHeight * .1f) {
		Hud::getInstance().makeTranslucent();
	} // bounds for when player is hidden behind UI elements

	if (m_sprite->m_dst.y > GameDefs::WindowHeight * 0.1f) {
		Hud::getInstance().makeOpaque();
	}

	// m_sprite->m_dst = m_sprite->m_dst; // moved // REDUNDANT???
	m_sprite->Render();
}

void ActorPlayer::move(float x, float y) { // not movement just explicit placement at a location
										   // m_sprite->m_dst.x += GameDefs::PlayerSpeed * x;
										   // m_sprite->m_dst.y += GameDefs::PlayerSpeed * y;

	// completely and utterly useless method also just not even implemented properly
}

void ActorPlayer::movement(const bool *state, double dt) {
	if (GameDefs::joystick != NULL) {
		int total, i;
		total = SDL_GetNumJoystickHats(GameDefs::joystick);
		for (i = 0; i < total; i++) {
			const Uint8 hat = SDL_GetJoystickHat(GameDefs::joystick, i);

			if (hat & SDL_HAT_RIGHT || state[SDL_SCANCODE_RIGHT]) {
				m_sprite->Offset_X(static_cast<float>(GameDefs::PlayerSpeed * dt));
			}
			if (hat & SDL_HAT_LEFT || state[SDL_SCANCODE_LEFT]) {
				m_sprite->Offset_X(-static_cast<float>(GameDefs::PlayerSpeed * dt));
			}
			if (hat & SDL_HAT_DOWN || state[SDL_SCANCODE_DOWN]) {
				m_sprite->Offset_Y(static_cast<float>(GameDefs::PlayerSpeed * dt));
			}
			if (hat & SDL_HAT_UP || state[SDL_SCANCODE_UP]) {
				m_sprite->Offset_Y(-static_cast<float>(GameDefs::PlayerSpeed * dt));
			}
		}
	} else if (GameDefs::joystick == NULL) {
		if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
			m_sprite->Offset_X(static_cast<float>(GameDefs::PlayerSpeed * dt));
			// SDL_Log("[ACTORPLAYER] Input received");
		}
		if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
			m_sprite->Offset_X(-static_cast<float>(GameDefs::PlayerSpeed * dt));
			// SDL_Log("[ACTORPLAYER] Input received");
		}
		if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
			m_sprite->Offset_Y(static_cast<float>(GameDefs::PlayerSpeed * dt));
			// SDL_Log("[ACTORPLAYER] Input received");
		}
		if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
			m_sprite->Offset_Y(-static_cast<float>(GameDefs::PlayerSpeed * dt));
			// SDL_Log("[ACTORPLAYER] Input received");
		}
	}
}

void ActorPlayer::collision(const bool *state) {
	if (m_sprite->m_dst.y > GameDefs::WindowHeight - m_sprite->m_dst.h) m_sprite->m_dst.y = GameDefs::WindowHeight - m_sprite->m_dst.h;
	if (m_sprite->m_dst.x > GameDefs::WindowWidth - m_sprite->m_dst.w) m_sprite->m_dst.x = GameDefs::WindowWidth - m_sprite->m_dst.w;
	if (m_sprite->m_dst.y < 0.0f) m_sprite->m_dst.y = 0.0f;
	if (m_sprite->m_dst.x < 0.0f) m_sprite->m_dst.x = 0.0f;
}

void ActorPlayer::swapWeapon(const bool *state) {
}

void ActorPlayer::shoot(const bool *state) {
}