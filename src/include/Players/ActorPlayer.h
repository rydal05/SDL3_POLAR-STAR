#ifndef ACTORPLAYER_H
#define ACTORPLAYER_H

#include "GameDefs.h"
#include "Player.h"
#include "Sprite.h"

#include <SDL3/SDL_scancode.h>

class ActorPlayer : public Player {
public:
	ActorPlayer();
	void update(double dt) override;
	void render() override;
	void move(float x, float y);

private:
	Sprite m_sprite;
	SDL_FRect m_dst;

	float SPEED = 0.250f;
};

#endif