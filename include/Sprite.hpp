#include <string>
#include <SDL3/SDL.h>

class Sprite {
    public:
        Sprite(SDL_Renderer *& renderer, std::string filepath);
        ~Sprite();

        void Draw(float x, float y, float w, float h);
        void Update();
        void Render(SDL_Renderer*& renderer);

        private:

        SDL_FRect m_rectangle;
        SDL_Texture* m_texture;      
};