#include <SDL3/SDL.h>
#include <string>

#include "ResourceManager.hpp"
#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer *&renderer, std::string filepath) {
	SDL_Surface *retrieveSurface = ResourceManager::GetInstance().GetSurface(filepath);
	m_texture = SDL_CreateTextureFromSurface(renderer, retrieveSurface);
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture);
}

void Sprite::Draw(float x, float y, float w, float h) {
	m_rectangle.x = x;
	m_rectangle.y = y;
	m_rectangle.w = w;
	m_rectangle.h = h;
}

void Sprite::Update() {
}

void Sprite::Render(SDL_Renderer *&renderer) {
	SDL_RenderTexture(renderer, m_texture, NULL, &m_rectangle);
}