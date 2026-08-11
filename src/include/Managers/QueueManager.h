#ifndef LOOP_QUEUES_H
#define LOOP_QUEUES_H

#include "superclasses/Bullet.h"
#include "superclasses/Entity.h"
#include "GameDefs.h"
#include "superclasses/Player.h"

#include <mutex>
#include <vector>

class Queue {
public:
	static Queue &getInstance();

	void render_queue() {
		for (auto &player : players) {
			player->Render();
		}

		for (auto &entity : entities) {
			entity->Render();
		}

		for (auto &bullet : bullets) {
			bullet->Render();
		}
	}

	void update_queue(double dt) {
		if (GameDefs::GAME_STATUS == GameDefs::GameMode::PAUSED) return;
		for (auto &player : players) {
			player->Update(dt);
		}

		for (auto &entity : entities) {
			entity->Update(dt);
		}

		for (auto &bullet : bullets) {
			bullet->Update(dt);
		}
	}

	void insert_player(ActorPlayer *plr) {
		players.push_back(plr);
	}

	void insert_entity(Entity *enm) {
		entities.push_back(enm);
	}

	void insert_bullets(Bullet *bul) {
		bullets.push_back(bul);
	}

private:
	Queue();
	Queue(Queue const &);
	Queue operator=(Queue const &);

	std::vector<ActorPlayer *> players;
	std::vector<Entity *> entities;
	std::vector<Bullet *> bullets;
};

#endif