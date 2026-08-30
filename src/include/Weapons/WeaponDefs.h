#ifndef WEAPON_DEFS_H
#define WEAPON_DEFS_H

#include <cstdint>

namespace weapondefs {
enum WeaponsList {
	POLAR,
	MISSILE,
	BUBBLE,
	SNAKE,
	SPUR,
	MACHINE,
	FIREBALL,
	NEMESIS,
	SWORD,
	BALROG,
	STAFF,

	WEAPON_LIST_SIZE
};

enum StatsOrder {
	FIRE_RATE,
	AMMO_MAX,
	DAMAGE,
	XP_REQUIRED,
	AMMO_PICKUP_SIZE,

	STATS_SIZE
};

} // namespace weapondefs

#endif