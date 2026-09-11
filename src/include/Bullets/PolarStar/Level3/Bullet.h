#include "superclasses/Bullet.h"

class PolarStar_Bul : public Bullet {
public:
	PolarStar_Bul(SDL_FRect c_dst) : Bullet("assets/img/Polar_Star_Players.bmp") {
		SDL_Log("Create bullet");



		m_sprite->Draw_Src(66, 5, 11, 4);
		m_sprite->Draw_Dst(c_dst.x, c_dst.y);
		m_sprite->Draw_Siz(16.0f, 16.0f);
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
};