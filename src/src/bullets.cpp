#include "bullets.hpp"

#include "gamedefs.hpp"

Bullet::Bullet()
	: m_sprite("assets/img/stg_story.bmp"), m_dst(m_sprite.m_dst), m_active(false) {
	m_sprite.Draw_Src(64, 0, 16, 16);
	m_sprite.Draw_Dst(0, 0);
	m_sprite.Draw_Siz(16 * SCALE, 16 * SCALE);
}

void Bullet::Reset(float x, float y) {
	m_dst.x = x;
	m_dst.y = y;
	m_active = true;
}

void Bullet::Update(double dt) {
	if (!m_active) return;

	m_dst.x += static_cast<float>(BUL_SPD * dt);
	if (m_dst.x > WINDOW_WIDTH) {
		m_active = false;
	}
}

void Bullet::Render() {
	if (!m_active) return;
	m_sprite.Render();
}
