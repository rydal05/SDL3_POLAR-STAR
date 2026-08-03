// #ifndef WEAPON_ICON_H
// #define WEAPON_ICON_H

// #include "superclasses/Entity.h"
// #include "superclasses/Sprite.h"
// #include "SDL3/SDL.h"

// class WeaponIcon : public Entity {
// public:
// 	WeaponIcon() : m_sprite(new Sprite("assets/img/stg_story_ui.bmp")) {
// 		m_sprite->Draw_Src(0, 8, 64, 16);
// 		m_sprite->Draw_Dst(8, 2);
// 		m_sprite->Draw_Siz(64, 16);
// 	}

//     void Update(double dt) override { SDL_Log("HELLO THIS IS AN OVERRIDE");  }; //this function will get called on HP change (not explicitly gain or loss as I might have some custom shenanigans implemented for funny HP realted things down the line)
// 	void Render() override { m_sprite->Render(); }

// private:
// 	Sprite *m_sprite;

//     //need to define rendering for XP bar size
//     //need to define slot for Level Number Placement
//     //need separate definitions for when level bar is maxed out
// };

// #endif

//yeah look man im not gonna work on this for a fat minute here's what needs to exist for it though
//mapping of each weapon icon to a src and size (destinations are universal)
//correlating ammo counters and renderings (and adjustments for if using an ammo-less gun)