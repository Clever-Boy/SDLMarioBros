#pragma once

#include "item.h"
#include "tile.h"
#include "enemy.h"

const int M_ENEMIES = 24;
const int M_ITEMS = 24;

// To implement in game class

struct LevelContent
{
	Tile* tileMap[TOTAL_TILES];
	Enemy* enemies[M_ENEMIES];
	Item* items[M_ITEMS];
};