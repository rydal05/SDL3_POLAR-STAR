/*

bubbline adjacent
summonables (like in exceed 3rd)


bomb: balrog throw

*/

#ifndef MISERY_H
#define MISERY_H

#include "ActorPlayer.h"
#include "Weapons/WeaponDefs.h"

class Misery : public ActorPlayer {
public:
	Misery() : ActorPlayer("assets/img/Polar_Star_Players.bmp") {
		SDL_Log("Loaded Actor: Misery");
		// weapons[0] = POLAR;

		m_sprite->Draw_Src(0, 16, 16, 16);
		m_sprite->Draw_Dst(320.0f / 2.0f, 240.0f / 2.0f);
		m_sprite->Draw_Siz(16.0f, 16.0f);
		m_gamepad = nullptr;
	}
};

#endif