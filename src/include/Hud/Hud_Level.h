#ifndef LEVEL_H
#define LEVEL_H

#include "superclasses/Entity.h"
#include "superclasses/Sprite.h"
#include "SDL3/SDL.h"

class Level : public Entity {
public:
	Level() : Entity("assets/img/stg_story_ui.bmp") {
		m_sprite->Draw_Src(0, 8, 64, 16);
		m_sprite->Draw_Dst(8, 2);
		m_sprite->Draw_Siz(64, 16);
	}

    void Update(double dt) override { SDL_Log("HELLO THIS IS AN OVERRIDE");  }; //this function will get called on HP change (not explicitly gain or loss as I might have some custom shenanigans implemented for funny HP realted things down the line)
	void Render() override { m_sprite->Render(); }

private:

    //need to define rendering for XP bar size
    //need to define slot for Level Number Placement
    //need separate definitions for when level bar is maxed out
};

#endif