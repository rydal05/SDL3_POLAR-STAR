#include "ResourceManager.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <vector>

#include <mutex>

class bgManager {
private:
	static bgManager *instancePtr;
	static std::mutex mtx;

	bgManager() {}

	std::vector<std::unique_ptr<Sprite>> moon;
	std::vector<std::unique_ptr<Sprite>> moon_paral;
	std::vector<float> moon_speeds = {-0.1f, -0.2f, -0.3f, -0.5f};

public:
	bgManager(const bgManager &obj) = delete;

	static bgManager *getInstance() {
		if (instancePtr == nullptr) {
			std::lock_guard<std::mutex> lock(mtx);
			if (instancePtr == nullptr) {
				instancePtr = new bgManager();
			}
		}
		return instancePtr;
	}

	void moonSceneInit();
	void moonSceneUpdate(double dt);
	void moonSceneRender();

	void renderScene();
	void switchScene();
};
