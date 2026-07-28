/*

has static weapon usage, limited to only sword, but has numerous inputs and has a different control flow compared to other playable characters. character built around point-blanking

levels influence damage dealt, not actual cave story weapon upgrades

Tap: Slash
Rapid Tap:
Hold: Yamato slash / level 3

*/

#ifndef KING_H
#define KING_H

#include "ActorPlayer.h"
#include "Weapons/WeaponDefs.h"

class King : public ActorPlayer {
public:
	King(): ActorPlayer("assets/img/Polar_Star_Players.bmp") {
        SDL_Log("Loaded Actor: King");
		// weapons[0] = POLAR;

		m_sprite->Draw_Src(0, 64, 16, 16);
		m_sprite->Draw_Dst(320.0f / 2.0f, 240.0f / 2.0f);
		m_sprite->Draw_Siz(16.0f, 16.0f);
		m_gamepad = nullptr;

        weapons[0] = SWORD;
	}
};

#endif