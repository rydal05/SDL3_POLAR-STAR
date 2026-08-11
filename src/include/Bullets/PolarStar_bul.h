#include "superclasses/Bullet.h"

class PolarStar_Bul : public Bullet {
    public:
    PolarStar_Bul() : Bullet("assets/img/Polar_Star_Players.bmp") {
        SDL_Log("Create bullet");

        m_sprite->Draw_Src(66,5,11,4);
        m_sprite->Draw_Dst(320.0f/2.0f, 240.0f/2.0f);
        m_sprite->Draw_Siz(16.0f, 16.0f);
    }

    void Update(double dt){
        m_sprite->Offset_X(X_speed*direction);
    }

    void Render(double dt){
        m_sprite->Render();
    }
    private:
    float X_speed = 0.25f;
    int damage = 1;
    bool playerOwnership = true;
    int direction = 1;
};