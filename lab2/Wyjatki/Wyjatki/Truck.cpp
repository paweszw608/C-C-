#include "Truck.h"

Truck::Truck()
{
}

Truck::~Truck()
{
}

Truck::Truck(int tl, int y, string b)
{
	if (y > 2018) throw invalid_argument("za duzy rok");
	else this->year = y;
	if (tl < 12) throw length_error("za dluga ciezarowka");
	else this->trucklength = tl;
	this->brand = b;
}
void Truck::PrintInfo()
{
	cout << "rok produkcji : " << this->year << " marka: " << this->brand << " dlugosc: " << this->trucklength << endl;
}
