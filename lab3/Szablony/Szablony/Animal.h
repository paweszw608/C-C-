#pragma once
#include <iostream>
using namespace std;
template<typename T1 = string, typename T2 = int>
class Animal
{
	string species, typeOfX, typeOfY;
protected:
	T1 x;
	T2 y;
public:
	Animal();
	virtual ~Animal();
	Animal(string, string, T1, string, T2);
	virtual void printEverything();
};

#include "Animal.tpp"