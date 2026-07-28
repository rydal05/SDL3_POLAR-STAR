#ifndef HP_H
#define HP_H

#include "Entity.h"
#include "Sprite.h"
#include "SDL3/SDL.h"

class HP : public Entity {
public:
	HP() : m_sprite(new Sprite("assets/img/stg_story_ui.bmp")) {
		m_sprite->Draw_Src(0, 24, 64, 8);
		m_sprite->Draw_Dst(8, 64);
		m_sprite->Draw_Siz(64, 8);
	}

    void Update(double dt) override { SDL_Log("HELLO THIS IS AN OVERRIDE");  }; //this function will get called on HP change (not explicitly gain or loss as I might have some custom shenanigans implemented for funny HP realted things down the line)
	void Render() override { m_sprite->Render(); }

private:
	Sprite *m_sprite;
};

#endif