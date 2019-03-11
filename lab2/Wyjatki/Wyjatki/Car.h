#pragma once
#include "Vehicle.h"
class Car: public Vehicle
{
public: 
	Car();
	~Car();
	Car(string, int, double);
	void PrintInfo();
private:
	double capacity;
};