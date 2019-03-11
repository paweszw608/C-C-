#include "Cat.h"

Cat::Cat()
{
}

Cat::~Cat()
{
}

Cat::Cat(string name, float weight)
{
	this->x = name;
	this->y = weight;
}

void Cat::printEverything()
{
	cout << "Name is: " << this->x << " weight: " << this->y << endl;
}
