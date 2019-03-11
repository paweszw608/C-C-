#pragma once
#include "Vehicle.h"
class Truck : public Vehicle
{
	int trucklength;
public:
	Truck();
	~Truck();
	Truck(int, int, string);
	void PrintInfo();
};
