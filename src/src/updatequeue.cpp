#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include <vector>

class Game {
public:
	void update() {
		for (auto &player : players) {
		}
	}

    void insert_player(){

    }

    void insert_enemy(){

    }
    
    void insert_bullets(){

    }

private:
	std::vector<Player *> players;
	std::vector<Enemy *> enemies;
	std::vector<Bullet *> bullets;


};