#include <iostream>

#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

template<typename T0, typename T1, typename T2>
void copy_while(T0 source_it, T1 dest_it, T2 stop_value)
{
	while (*source_it != stop_value)
	{
		*dest_it = *source_it;
		source_it++;
	}
}

int main()
{	
	//1 
	vector <int> wektor{ 1,2,3,3,2,1 };
	//2
	list <double> lista{ -5,-4,-3,-2,-1 };
	//3
	copy(wektor.begin(), wektor.begin() + 3, back_inserter(lista));
	//4
	auto it = find_if(lista.begin(), lista.end(), [](double x) {return x > 0; });

	insert_iterator<list<double>> insert_iter(lista, it);

	insert_iter = 0;
	//5
	insert_iter = 0.5;
	insert_iter = 2.7;
	//6
	it = is_sorted_until(lista.begin(), lista.end());
	it--;
	lista.erase(it);
	//7
	wektor.clear();
	copy(lista.begin(), lista.end(), back_inserter(wektor));
	//8
	random_shuffle(wektor.begin(), wektor.end());
	//9
	sort(wektor.begin(), wektor.end());
	//10
	bool czyWektorJestPosortowany = is_sorted(wektor.begin(), wektor.end());
	//11
	if (czyWektorJestPosortowany == true)
	{
		auto it_w = lower_bound(wektor.begin(), wektor.end(), -3);
		cout << *it_w << endl << endl;
	}
	//12
		// patrz wyzej
	//13
	vector<string> jakisNapis = { "Mrowka", "Osa", "Mucha", "STOP", "Pomarncza", "Cytryna" };
	//14
	vector<string> owady;
	copy_while(jakisNapis.begin(), back_inserter(owady), "STOP");




	cout << "lista :" << endl;
	for (auto el : lista) cout << el << " ";
	
	
	
	cout << endl << "wektor:" << endl;
	for (auto el : wektor) cout << el << " "; cout << endl;
	


	cout  << "owady:" << endl;
	for (auto el : owady) cout << el << " "; cout << endl << endl;
	
	
	
	
	
	system("pause");	return 0;

}