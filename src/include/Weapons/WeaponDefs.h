#ifndef WEAPON_DEFS_H
#define WEAPON_DEFS_H

#include <cstdint>

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

    LIST_SIZE
};

enum StatsOrder {
    FIRE_RATE,
    AMMO_MAX,
    DAMAGE_LEVEL_ONE,
    DAMAGE_LEVEL_TWO,
    DAMAGE_LEVEL_THREE,
    XP_REQUIRED_TWO,
    XP_REQUIRED_THREE,
    AMMO_PICKUP_SIZE,

    STATS_SIZE
};

// std::int8_t stats[STATS_SIZE][LIST_SIZE] = {
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
//     1,1,1,1,1,1,1,1,1,1,1,
// };

#endif