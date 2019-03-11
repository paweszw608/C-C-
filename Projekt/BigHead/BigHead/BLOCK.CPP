#include "Block.h"

Block::Block()
{
	outlineThickness = 5;
	moveableObject.setFillColor(Color::Transparent);
	moveableObject.setOutlineThickness(5);
}
Block::~Block()
{
}

void Block::setSize(Vector2f size)
{
	moveableObject.setSize(size);
}

void Block::setColor(int index)
{
	switch (index)
	{
	case 0: {
		moveableObject.setOutlineColor(Color(255, 0, 0, 255)); // red
		break;
	}
	case 1: {
		moveableObject.setOutlineColor(Color(0, 32, 255, 255)); // blue
		break;
	}
	case 2: {
		moveableObject.setOutlineColor(Color(0, 255, 0, 255)); // green
		break;
	}
	case 3: {
		moveableObject.setOutlineColor(Color(255, 0, 255, 255)); // purple
		break;
	case 4: {
		moveableObject.setOutlineColor(Color(247, 108, 2, 255)); // orange
		break;
	}
	default:
		break;
	}
	}
}

