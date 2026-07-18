#include <SDL3/SDL.h>
#include <string>

#include "GameDefs.h"
#include "Managers/ResourceManager.h"
#include "Sprite.h"

Sprite::Sprite(const char *filepath) {
	char *new_filepath = NULL;
	SDL_asprintf(&new_filepath, "%s%s", SDL_GetBasePath(), filepath);
	SDL_Surface *retrieveSurface = ResourceManager::GetInstance().GetSurface(new_filepath);
	m_texture = SDL_CreateTextureFromSurface(GameDefs::g_renderer, retrieveSurface);
	SDL_free(new_filepath);
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture);
}

void Sprite::Draw_Src(float x, float y, float w, float h) {
	m_src.x = x;
	m_src.y = y;
	m_src.w = w;
	m_src.h = h;
}

void Sprite::Draw_Dst(float x, float y) {
	this->m_dst.x = x * GameDefs::ScaleFactor;
	this->m_dst.y = y * GameDefs::ScaleFactor;
}

void Sprite::Draw_X(float x) {
	this->m_dst.x = x * GameDefs::ScaleFactor;
}

void Sprite::Draw_Y(float y) {
	this->m_dst.y = y * GameDefs::ScaleFactor;
}

void Sprite::Draw_Siz(float w, float h) {
	this->m_dst.w = w * GameDefs::ScaleFactor;
	this->m_dst.h = h * GameDefs::ScaleFactor;
}

void Sprite::Update(double dt) {
}

void Sprite::Render() {
	SDL_SetTextureScaleMode(m_texture, SDL_SCALEMODE_NEAREST);
	SDL_RenderTexture(GameDefs::g_renderer, m_texture, &m_src, &m_dst);
}
