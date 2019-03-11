#include "Car.h"

Car::Car()
{
}

Car::~Car()
{
}

Car::Car(string b, int y, double c)
{
	if(y > 2018) throw invalid_argument("za duzy rok");
	else this->year = y;
	if (c < 0.9 || c  > 5.0) throw  invalid_argument("zla pojemnosc");
	else this->capacity = c;

	this->brand = b;
}

void Car::PrintInfo()
{
	cout << "rok produkcji : " << this->year << " marka: " << this->brand << " pojemnoœæ: " << this->capacity << endl;
}
