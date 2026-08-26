/*
gains weapons as stages progress
has access to the following weapons

polar star, missile launcher, bubbline, snake (sidegrade from polar star), spur (upgrade from polar star)



*/

#ifndef QUOTE_H
#define QUOTE_H

#include "superclasses/Player.h"

class Quote : public ActorPlayer {
public:
	Quote(): ActorPlayer("assets/img/Polar_Star_Players.bmp") {
        SDL_Log("Loaded Actor: Quote");
		// weapons[0] = POLAR;

		m_sprite->Draw_Src(0, 0, 16, 16);
		m_sprite->Draw_Dst(320.0f / 2.0f, 240.0f / 2.0f);
		m_sprite->Draw_Siz(16.0f, 16.0f);
		m_gamepad = nullptr;

        weapons[POLAR] = 1;
	}
};

#endif