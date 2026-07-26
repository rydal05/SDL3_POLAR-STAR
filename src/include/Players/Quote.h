/*
gains weapons as stages progress
has access to the following weapons

polar star, missile launcher, bubbline, snake (sidegrade from polar star), spur (upgrade from polar star)



*/

#include "ActorPlayer.h"
#include "Weapons/WeaponDefs.h"

class Quote : public ActorPlayer {
public:
	Quote();
    ~Quote();



private:
    Sprite *m_sprite = new Sprite("assets/img/stg_story.bmp");

    
};