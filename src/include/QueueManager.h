#ifndef LOOP_QUEUES_H
#define LOOP_QUEUES_H

#include "Bullet.h"
#include "Entity.h"
#include "Player.h"
#include "GameDefs.h"

#include <mutex>
#include <vector>

class Game {
public:
    static Game& getInstance() {
        std::call_once(initInstanceFlag, [](){
            instance = new Game();
        });
        return *instance;
    }

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

	void update_queue(double dt) {
        if(GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;
		for (auto &player : players) {
            player->update(dt);
		}

        for (auto &entity : entities) {
            entity->update(dt);
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
    Game() = default;
    ~Game() = default;;

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static std::mutex mtx;
    static std::once_flag initInstanceFlag;
    static Game* instance;

	std::vector<Player *> players;
	std::vector<Entity *> entities;
	std::vector<Bullet *> bullets;
};

std::mutex Game::mtx;
std::once_flag Game::initInstanceFlag;
Game* Game::instance = nullptr;

#endif