#include "Bus.h"

Bus::Bus()
{
}

Bus::~Bus()
{
}

Bus::Bus(int y, int p, int s, string b)
{
	if (p > s) throw "za duzo pasazerow a za malo siedzien";

	if (y > 2018) throw invalid_argument("za duzy rok");
	else this->year = y;

	if (p < 6) throw invalid_argument("za malo pasazerów");
	else this->passangers = p;

	this->brand = b;
	this->seats = s;
}

void Bus::PrintInfo()
{
	cout << "rok produkcji : " << this->year << " marka: " << this->brand << " pasazerow: " << this->passangers << endl;
}
