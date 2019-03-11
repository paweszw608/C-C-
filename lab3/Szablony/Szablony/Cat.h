#pragma once
#include "Animal.h"
#include <string>
class Cat: protected Animal<string, float>
{
public:
	Cat();
	~Cat();
	Cat(string, float);
	void printEverything();
};
