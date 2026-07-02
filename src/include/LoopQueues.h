#ifndef LOOP_QUEUES_H
#define LOOP_QUEUES_H

#include "Bullet.h"
#include "Entity.h"
#include "Player.h"
#include "GameDefs.h"

#include <vector>

class Game {
public:
    void render_queue() {
        for (auto &player : players) {
            player->render();
		}

        for (auto &entity : entities) {
            entity->render();
		}

        for (auto &bullet : bullets) {
            bullet->render();
		}
    }

	void update_queue() {
        if(GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;
		for (auto &player : players) {
            player->update();
		}

        for (auto &entity : entities) {
            entity->update();
		}

        for (auto &bullet : bullets) {
            bullet->update();
		}
	}

    void insert_player(Player *plr){
        players.push_back(plr);
    }

    void insert_entity(Entity *enm){
        entities.push_back(enm);
    }

    void insert_bullets(Bullet *bul){
        bullets.push_back(bul);
    }

private:
	std::vector<Player *> players;
	std::vector<Entity *> entities;
	std::vector<Bullet *> bullets;
};

#endif