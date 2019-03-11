#pragma once
#include "Movealbe.h"
class Coin : public Moveable<CircleShape>
{
public:
	Coin(float size);
	Coin();
	~Coin();
};