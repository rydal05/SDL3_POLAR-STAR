/*

gains weapons as stages progress
has access to the following weapons

machinegun, missile launcher, fireball, bubbline, nemesis

 */

#ifndef CURLY_H
#define CURLY_H

#include "superclasses/Player.h"

class Curly : public ActorPlayer {
public:
	Curly(): ActorPlayer("assets/img/Polar_Star_Players.bmp") {
        SDL_Log("Loaded Actor: Curly");
		// weapons[0] = POLAR;

		m_sprite->Draw_Src(0, 48, 16, 16);
		m_sprite->Draw_Dst(320.0f / 2.0f, 240.0f / 2.0f);
		m_sprite->Draw_Siz(16.0f, 16.0f);
		m_gamepad = nullptr;

        // arsenal[0] = new ;
	}
};

#endif