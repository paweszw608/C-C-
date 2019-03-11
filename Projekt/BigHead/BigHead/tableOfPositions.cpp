#include "tableOfPositions.h"

TableOfPositions::TableOfPositions()
{
}

TableOfPositions::~TableOfPositions()
{
}

float & TableOfPositions::operator[](int index)
{
	return tab[index];
}

void TableOfPositions::setMid(float mid)
{
	tab[1] = this->middle = mid;
}

void TableOfPositions::setTop(float top)
{
	tab[0] = this->top = top;
}

void TableOfPositions::setBot(float bot)
{
	tab[2] = this->bottom = bot;
}
