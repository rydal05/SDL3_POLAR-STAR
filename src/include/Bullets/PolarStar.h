#include "superclasses/Bullet.h"

class Bul_PS : public Bullet {
public:
	Bul_PS(SDL_FRect c_dst, int level, int charge) : Bullet("assets/img/Polar_Star_Players.bmp") {
		SDL_Log("Create bullet");

		offset_X = c_dst.x + c_dst.w;
		offset_Y = c_dst.y + (c_dst.h / 2);

		m_sprite->Draw_Src(66, 5, 11, 4);
		m_sprite->Draw_Dst(offset_X, offset_Y);
		m_sprite->Draw_Siz(11.0f, 4.0f);
	}

	virtual void Update(double dt) override {
		m_sprite->Offset_X(X_speed * direction);
	}

	virtual void Render() override {
		m_sprite->Render();
	}

private:
	float X_speed = 10.25f;
	int damage = 1;
	// bool playerOwnership = true;
	int direction = 1;
	float offset_X;
	float offset_Y = 8.0f;
};