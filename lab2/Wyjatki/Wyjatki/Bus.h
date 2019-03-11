#pragma once
#include "Vehicle.h"
class Bus : public Vehicle
{
	int passangers, seats;
public:
	Bus();
	~Bus();
	Bus(int, int, int, string);
	void PrintInfo();
};
