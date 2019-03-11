#include "Bus.h"
#include "Car.h"
#include "Vehicle.h"
#include "Truck.h"
#include <typeinfo>
int main()
{
	Vehicle pojazd;
	try
	{
		Vehicle * vh =  &pojazd;
		string nameOfVeh = typeid(*vh).name();
	}
	catch (bad_typeid & bt)
	{
		cout << bt.what() << endl;
	}

	// ROBI BUSA:

	try
	{
		Bus bus1(2017,70, 60, "Solaris");
		bus1.PrintInfo();		
	}
	catch (char * s)
	{
		cout << s << endl;
	}
	catch (invalid_argument ia)
	{
		cout << ia.what() << endl;
	}

	// ROBI AUTO:

	try
	{
		Car car1("BMW", 3000, 3.0);
		car1.PrintInfo();
	}
	catch (invalid_argument ia)
	{
		cout << ia.what() << endl;
	}
	try
	{
		Truck truck1(10, 2001, "Volvo");
		truck1.PrintInfo();
	}
	catch (invalid_argument ia)
	{
		cout << ia.what() << endl;
	}
	catch (length_error le)
	{
		cout << le.what() << endl;
	}
	system("pause");
	return 0;
}