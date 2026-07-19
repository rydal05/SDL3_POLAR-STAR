#include "Backgrounds/Star.h"

Stars::Stars(){
    for (size_t i = 0; i < starsQuantity; i++) {
		auto star = std::make_unique<Sprite>("assets/img/moon_stars_polarstar.bmp");
		float randY = float(rand() % (GameDefs::WindowHeight / 3));
		float randX = float(rand() % GameDefs::WindowWidth);

		star->Draw_Src(0, 0, 5, 5);
		star->Draw_Dst(randX, randY);
		star->Draw_Siz(5, 5);

		starsBG.push_back(std::move(star));
		SDL_Log("Created star %d at pos %.2f %.2f", i, randX, randY);
	}
}