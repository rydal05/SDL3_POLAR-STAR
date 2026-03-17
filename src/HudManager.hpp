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

	bool visible = true;

	std::vector<std::unique_ptr<Sprite>> gameplayElements;

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

	void HudUpdate();
	void HudRender();
	void hudStateManager();
	void makeTranslucent();
	void makeOpaque();

	void gameplayHudInit();
};
