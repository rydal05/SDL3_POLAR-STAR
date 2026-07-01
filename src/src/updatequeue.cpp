#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include <vector>

class Game {
public:
	void update_queue() {
		for (auto &player : players) {
            player->update();
		}

        for (auto &enemy : enemies) {
            enemy->update();
		}

        for (auto &bullet : bullets) {
            bullet->update();
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