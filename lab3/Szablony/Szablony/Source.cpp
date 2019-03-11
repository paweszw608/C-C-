using namespace std;
#include <typeinfo>
#include "Animal.h"
#include "Cat.h"
template<typename T>
T printType(T x)
{
	cout << "Type is: " << typeid(x).name() << endl;
	return x;
}
int main()
{
	Animal<string, int>zwierzatko1("pies", "kolor", "czarny", "wiek", 10);
	zwierzatko1.printEverything();
	Animal<float, int>zwierzatko2("zlow", "waga", 1.4, "liczba nog", 4);
	zwierzatko2.printEverything();
	Animal<int, string>zwierzatko3("papuga", "liczba skrzydel", 2, "imie", "Papuga Zosia");
	zwierzatko3.printEverything();

	Cat cat1("Kizia", 10);
	cat1.printEverything();

	int var1 = 4; printType(var1);
	char var2 = 'p'; printType(var2);
	double var3 = 21.37; printType(var3);

	system("pause");
	return 0;
}