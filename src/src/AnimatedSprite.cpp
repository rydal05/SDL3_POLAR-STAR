#include <SDL3/SDL.h>
#include <string>

#include "Sprite.h"
#include "Managers/ResourceManager.h"
#include "GameDefs.h"

AnimatedSprite::AnimatedSprite(const char* filepath, int frames){
    char *new_filepath = NULL;
	SDL_asprintf(&new_filepath, "%s%s", SDL_GetBasePath(), filepath);
	SDL_Surface *retrieveSurface = ResourceManager::GetInstance().GetSurface(new_filepath);
	m_texture = SDL_CreateTextureFromSurface(GameDefs::g_renderer, retrieveSurface);
	SDL_free(new_filepath);

    this->frames = frames;
}



void AnimatedSprite::Draw(int x, int y, int w, int h){

}

void AnimatedSprite::PlayFrame(int x, int y, int w, int h, int frame){

}

void AnimatedSprite::Update(){
    
}

void AnimatedSprite::Render(){

}