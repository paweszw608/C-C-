#include "Coin.h"

Coin::Coin(float size)
{
	moveableObject.setRadius(size);
	moveableObject.setFillColor(Color(249, 161, 1));
}

Coin::Coin() : Coin(1)
{
}

Coin::~Coin()
{
}

