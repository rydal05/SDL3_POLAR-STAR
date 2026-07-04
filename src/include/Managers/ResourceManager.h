#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <unordered_map>

#include <SDL3/SDL.h>

class ResourceManager {
public:
	static ResourceManager &GetInstance();

	SDL_Surface *GetSurface(std::string filepath);

private:
	ResourceManager();
	ResourceManager(ResourceManager const &);
	ResourceManager operator=(ResourceManager const &);

	std::unordered_map<std::string, SDL_Surface *> m_surfaces;
};

#endif