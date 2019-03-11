#include "blocksPosition.h"

BlockPosition::BlockPosition()
{
}

BlockPosition::~BlockPosition()
{
}

float & BlockPosition::operator[](int index)
{
	return tab[index];
}

void BlockPosition::setMid(float mid)
{
	tab[1] = this->middle = mid;
}

void BlockPosition::setTop(float top)
{
	tab[0] = this->top = top;
}

void BlockPosition::setBot(float bot)
{
	tab[2] = this->bottom = bot;
}
