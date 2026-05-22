#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include <string>
#include <SDL3/SDL.h>

class AnimatedSprite{
    public:
        AnimatedSprite(SDL_Renderer*& renderer, std::string filepath);

        ~AnimatedSprite();

        void Draw(int x, int y, int w, int h);

        void PlayFrame(int x, int y, int w, int h, int frame);

        void Update();

        void Render(SDL_Renderer *& renderer);

    private:
        SDL_FRect m_src;
        SDL_Texture *m_texture;
};

#endif