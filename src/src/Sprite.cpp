#include <SDL3/SDL.h>
#include <string>

#include "ResourceManager.h"
#include "Sprite.h"
#include "GameDefs.h"

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

void Sprite::Draw_Src(int x, int y, int w, int h) {
	m_src.x = x;
	m_src.y = y;
	m_src.w = w;
	m_src.h = h;
}

void Sprite::Draw_Dst(int x, int y) {
	m_dst.x = x;
	m_dst.y = y;
}

void Sprite::Draw_Siz(int w, int h) {
	m_dst.w = w;
	m_dst.h = h;
}

void Sprite::Update(double dt) {
}

void Sprite::Render() {
	SDL_SetTextureScaleMode(m_texture, SDL_SCALEMODE_NEAREST);
	SDL_RenderTexture(GameDefs::g_renderer, m_texture, &m_src, &m_dst);
}
