#include "ResourceManager.hpp"
#include <iostream>

ResourceManager::ResourceManager() {
}

ResourceManager::ResourceManager(ResourceManager const &) {
}

ResourceManager ResourceManager::operator=(ResourceManager const &rhs) {
	return *this;
}

ResourceManager &ResourceManager::GetInstance() {
	static ResourceManager *s_instance = new ResourceManager;
	return *s_instance;
}

SDL_Surface *ResourceManager::GetSurface(std::string filepath) {
	std::cout << "Filepath given: " << filepath << std::endl;

	auto search = m_surfaces.find(filepath);
	if (search != m_surfaces.end()) {
		std::cout << "Given path was successfuly retrieved." << std::endl;
		return m_surfaces[filepath];
	} else {
		std::cout << "Given path was added to database." << std::endl;
		SDL_Surface *surface = SDL_LoadBMP(filepath.c_str());
		m_surfaces.insert(std::make_pair(filepath, surface));
		return m_surfaces[filepath];
	}
	std::cout << "[RESOURCEMANAGER] Panic" << std::endl;

	return nullptr;
}
