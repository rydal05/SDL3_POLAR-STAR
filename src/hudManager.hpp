#include "Sprite.hpp"
#include <SDL3/SDL.h>
#include <memory>
#include <mutex>
#include <vector>

class HudManager {
private:
	static HudManager *instancePtr;
	static std::mutex mtx;

	HudManager() {}

	std::vector<std::unique_ptr<Sprite>> gameplayElements;

	SDL_Renderer *m_renderer = nullptr;

public:
	HudManager(const HudManager &obj) = delete;

	static HudManager *getInstance() {
		if (instancePtr == nullptr) {
			std::lock_guard<std::mutex> lock(mtx);
			if (instancePtr == nullptr) {
				instancePtr = new HudManager();
			}
		}
		return instancePtr;
	}

	void passRenderer(SDL_Renderer *renderer) { m_renderer = renderer; }

	void hudUpdate();
	void hudDraw();
	void hudStateManager();

	void gameplayHudInit();
};
