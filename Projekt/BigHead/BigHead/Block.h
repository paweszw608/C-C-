#pragma once
#include "Movealbe.h"
class Block: public Moveable<RectangleShape>
{
public:
	Block();
	~Block();

	void setSize(Vector2f size);
	void setColor(int index);
	int outlineThickness;
};