#include "ActorPlayer.h"
#include "Managers/HudManager.h"

ActorPlayer::ActorPlayer() : m_sprite("assets/img/stg_story.bmp") {
	m_dst.x = GameDefs::WindowWidth / 2.0f;
	m_dst.y = GameDefs::WindowHeight / 2.0f;
	m_dst.w = 16 * GameDefs::ScaleFactor;
	m_dst.h = 16 * GameDefs::ScaleFactor;

	m_sprite.Draw_Src(0, 0, 16, 16);
	m_sprite.Draw_Dst(m_dst.x, m_dst.y);
	m_sprite.Draw_Siz(m_dst.w, m_dst.h);

	SDL_Log("[ACTORPLAYER] successful instantiation");
}

void ActorPlayer::update(double dt) {
	const bool *state = SDL_GetKeyboardState(nullptr);
	if (state[SDL_SCANCODE_UP]) {
		m_dst.y -= static_cast<float>(SPEED * dt);
		// SDL_Log("[ACTORPLAYER] Input received");
	}
	if (state[SDL_SCANCODE_LEFT]) {
		m_dst.x -= static_cast<float>(SPEED * dt);
		// SDL_Log("[ACTORPLAYER] Input received");
	}
	if (state[SDL_SCANCODE_DOWN]) {
		m_dst.y += static_cast<float>(SPEED * dt);
		// SDL_Log("[ACTORPLAYER] Input received");
	}
	if (state[SDL_SCANCODE_RIGHT]) {
		m_dst.x += static_cast<float>(SPEED * dt);
		// SDL_Log("[ACTORPLAYER] Input received");
	}

	if (m_dst.y > 448.0f) m_dst.y = 448.0f;
	if (m_dst.x > 608.0f) m_dst.x = 608.0f;
	if (m_dst.y < 0.0f) m_dst.y = 0.0f;
	if (m_dst.x < 0.0f) m_dst.x = 0.0f;

	if (m_dst.y < 64) {
			Hud::getInstance().makeTranslucent();
		} // bounds for when player is hidden behind UI elements

		if (m_dst.y > 64) {
			Hud::getInstance().makeOpaque();
		}

	// ensure parity with sprite
	m_sprite.m_dst = m_dst;

	// SDL_Log("[ACTORPLAYER] update finished");
}

void ActorPlayer::render() {
	m_sprite.Render();
}

void ActorPlayer::move(float x, float y) {
	m_dst.x += SPEED * x;
	m_dst.y += SPEED * y;
}