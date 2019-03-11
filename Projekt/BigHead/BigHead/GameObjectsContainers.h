#pragma once
#include "Player.h"
#include "Block.h"
#include "Coin.h"
#include "Alien.h"
#include "Ufo.h"
class GameObjectsContainers
{
public:
	GameObjectsContainers() {};
	virtual ~GameObjectsContainers() {};
protected:
	vector<Block> blocksVec;
	vector<Block>::iterator blocksIt;
	vector<Coin> coinsVec;
	vector<Coin>::iterator coinsIt;
	vector<Alien> alienVec;
	vector<Alien>::iterator alienIt;

	vector<Sprite> lifeHeartVec;


};