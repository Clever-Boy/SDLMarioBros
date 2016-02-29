#pragma once

#include <vector>

#include "item.h"
#include "tile.h"
#include "enemy.h"



// To implement in game class

struct LevelContent
{
	Tile* tileMap[TOTAL_TILES];
	std::vector<Enemy> ennemies;
	std::vector<Item> items;
};