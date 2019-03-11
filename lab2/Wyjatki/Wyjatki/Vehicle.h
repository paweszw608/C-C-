#pragma once
#include <string>
#include <iostream>
using namespace std;
class Vehicle
{
public:
	Vehicle();
	virtual ~Vehicle();
protected:
	string brand;
	int year;
	virtual void PrintInfo();
};