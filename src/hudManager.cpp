#include "hudManager.hpp"
#include "gamedefs.hpp"

void HudManager::gameplayHudInit() {

	Sprite hp_lv_bg(m_renderer, "asset/img/stg_story_ui.bmp");
	hp_lv_bg.Draw_Src(0, 0, 64, 32);
	hp_lv_bg.Draw_Dst(0, 0, 64 * SCALE, 32 * SCALE);

	Sprite gunIcon(m_renderer, "asset/img/stg_story_ui.bmp");
	gunIcon.Draw_Src(0, 32, 16, 16);
	gunIcon.Draw_Dst(0, 0, 16 * SCALE, 16 * SCALE);

	Sprite levelIcon(m_renderer, "asset/img/stg_story_ui.bmp");
	levelIcon.Draw_Src(8, 64, 8, 8);
	levelIcon.Draw_Dst(16 * SCALE, 16 * SCALE, 8 * SCALE, 8 * SCALE);
}
