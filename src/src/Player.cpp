#include "Player.h"
#include "GameDefs.h"

#include <SDL3/SDL_scancode.h>

class ActorPlayer : public Player {
	public:
	void update() override {
		
	}

	void render() override {

	}
};

// Player::Player()
// 	: m_sprite("assets/img/stg_story.bmp"), m_dst(m_sprite.m_dst), m_fireCooldown(0.0) {
// 	m_sprite.Draw_Src(0, 0, 16, 16);
// 	m_sprite.Draw_Dst(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
// 	m_sprite.Draw_Siz(16 * SCALE, 16 * SCALE);
// }

// void Player::Update(double dt, Bullet &bullet) {
// 	const bool *state = SDL_GetKeyboardState(nullptr);

// 	if (state[SDL_SCANCODE_UP]) {
// 		m_dst.y -= static_cast<float>(PLR_SPEED * dt);
// 	}
// 	if (state[SDL_SCANCODE_LEFT]) {
// 		m_dst.x -= static_cast<float>(PLR_SPEED * dt);
// 	}
// 	if (state[SDL_SCANCODE_DOWN]) {
// 		m_dst.y += static_cast<float>(PLR_SPEED * dt);
// 	}
// 	if (state[SDL_SCANCODE_RIGHT]) {
// 		m_dst.x += static_cast<float>(PLR_SPEED * dt);
// 	}

// 	m_fireCooldown -= dt / 1000.0;
// 	if (m_fireCooldown <= 0.0 && state[SDL_SCANCODE_X]) {
// 		bullet.Reset(m_dst.x + 10.0f, m_dst.y);
// 		m_fireCooldown = FIRE_RATE;
// 	}

// 	if (m_dst.y > 448.0f) m_dst.y = 448.0f;
// 	if (m_dst.y < 0.0f) m_dst.y = 0.0f;
// 	if (m_dst.x < 0.0f) m_dst.x = 0.0f;
// 	if (m_dst.x > 608.0f) m_dst.x = 608.0f;
// }

// void Player::Render() {
// 	m_sprite.Render();
// 	printf("player rendered\n");
// }
