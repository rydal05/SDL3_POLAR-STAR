#include "Managers/HudManager.h"

Hud::Hud(){}

Hud::Hud(Hud const &){}

Hud Hud::operator=(Hud const &rhs){
    return *this;
}

Hud &Hud::getInstance(){
    static Hud *hud_instance = new Hud;
    return *hud_instance;
}