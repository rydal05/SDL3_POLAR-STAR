#ifndef POLAR_STAR_H
#define POLAR_STAR_H

#include "Bullets/PolarStar.h"
#include "WeaponDefs.h"
#include "superclasses/Entity.h"
#include "superclasses/Weapon.h"

#include "Managers/QueueManager.h"

class PolarStar : public Weapon {
public:
	PolarStar(Entity *callee) : Weapon("assets/img/Polar_Star_Players.bmp") {
		this->owner = callee;

		m_sprite->Draw_Src(51, 6, 9, 3);
		m_sprite->Draw_Dst(owner->getSprite()->get_X() + offset_X, owner->getSprite()->get_Y() + offset_Y);
		m_sprite->Draw_Siz(9, 3);
		// ok so i can either explicitly state weapon stats in here but that FEELS intrinically wasteful like I don't know if it would be better to manage that entirely within the weapondefs header but in here it is a lot easier to look at specific stats for weapons when i want to rather than looking through a giant disgusting list
	}
	~PolarStar() {}

	virtual void Update(double dt) override {
		m_sprite->Draw_Dst(owner->getSprite()->get_X() + offset_X, owner->getSprite()->get_Y() + offset_Y);
	};
	virtual void Render() override {
		m_sprite->Render();
	};

	void Shoot() {
		SDL_Log("FIRED FROM POLARSTAR UNSPECIFIED SHOT TYPE");

		Queue::getInstance().insert_bullets(new Bul_PS(owner->getSprite()->get_dst(), -1, -1));
	}

private:
	float stats[(int)(weapondefs::STATS_SIZE)][4] = {0};
	float offset_X = 12.0f;
	float offset_Y = 9.0f;
};

#endif