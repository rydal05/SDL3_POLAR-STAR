#include "Player.h"
#include "GameDefs.h"
#include "Sprite.h"

#include <SDL3/SDL_scancode.h>

class ActorPlayer : public Player {
public:
	ActorPlayer() : m_sprite("assets/img/stg_story.bmp") {
		m_dst->x = 0.0f;
		m_dst->y = 0.0f;
		m_dst->w = 16 * GameDefs::ScaleFactor;
		m_dst->h = 16 * GameDefs::ScaleFactor;

		m_sprite.Draw_Src(0, 0, 16, 16);
		m_sprite.Draw_Dst(m_dst->x, m_dst->y);
		m_sprite.Draw_Siz(m_dst->w, m_dst->h);
	}

	void update(double dt) override {
		const bool *state = SDL_GetKeyboardState(nullptr);
		if (state[SDL_SCANCODE_UP]) {
			m_dst->y -= static_cast<float>(SPEED * dt);
		}
		if (state[SDL_SCANCODE_LEFT]) {
			m_dst->x -= static_cast<float>(SPEED * dt);
		}
		if (state[SDL_SCANCODE_DOWN]) {
			m_dst->y += static_cast<float>(SPEED * dt);
		}
		if (state[SDL_SCANCODE_RIGHT]) {
			m_dst->x += static_cast<float>(SPEED * dt);
		}
		if (m_dst->y > 448.0f) m_dst->y = 448.0f;
		if (m_dst->x > 608.0f) m_dst->x = 608.0f;
		if (m_dst->y < 0.0f) m_dst->y = 0.0f;
		if (m_dst->x < 0.0f) m_dst->x = 0.0f;
	}

	void render() override {
		m_sprite.Render();
	}

	void move(int x, int y) {
		m_dst->x += SPEED * x;
		m_dst->y += SPEED * y;
	}

private:
	Sprite m_sprite;
	SDL_FRect *m_dst;

	float SPEED = 1.0f;
};

// Player::Player()
// 	, m_dst(m_sprite.m_dst), m_fireCooldown(0.0) {

// }

// void Player::Update(double dt, Bullet &bullet) {

// 	m_fireCooldown -= dt / 1000.0;
// 	if (m_fireCooldown <= 0.0 && state[SDL_SCANCODE_X]) {
// 		bullet.Reset(m_dst.x + 10.0f, m_dst.y);
// 		m_fireCooldown = FIRE_RATE;
// 	}

// }
