#include <iostream>
#include <string>
#include <thread>
using namespace std;
class Car
{
public:
	string marka, model;
	Car() {}
	~Car() {}
	void print_car_info() { cout << marka << " " << model << endl; }
};

struct list
{
	Car car;
	list * next;
};

int car_counter = 0;
thread::id main_thread_id;

void add_to_list(list *& head, const string mark, const string model)
{
	list * nowy = new list;
	nowy->car.marka = mark;
	nowy->car.model = model;
	if (head == nullptr)
	{
		head = nowy;
		nowy->next = nullptr;
		
	}
	else
	{
		list * tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		nowy->next = nullptr;
		tmp->next = nowy;
	}

	car_counter++;
}
void print_all_cars(list * head)
{
	while (head != nullptr)
	{
		head->car.print_car_info();
		head = head->next;
	}
}

bool is_main_thread() {
	if (main_thread_id == this_thread::get_id())
	{
		cout << "true" << endl;
		return true;
	}
	else
	{
		cout << "false" << endl;
		return false;
	}
}
void pause_thread(const int milliseconds)
{
	this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void print_all_cars2(list * head, int milliseconds)
{
	pause_thread(milliseconds);
	while (head != nullptr)
	{
		head->car.print_car_info();
		head = head->next;
		pause_thread(milliseconds);
	}
}
void delete_list(list *& head)
{
	list * tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main()
{
	list * glowa = nullptr;

	main_thread_id = this_thread::get_id();
	is_main_thread();
	thread a(is_main_thread);
	a.join();
	is_main_thread();

	thread t1(add_to_list, ref(glowa), "BMW", "M4");
	t1.join();

	thread t2(print_all_cars, ref(glowa));
	t2.join();

	cout << endl << endl;

	add_to_list(glowa, "Ferrari", "Italia");
	add_to_list(glowa, "Chevrolet", "Camaro");
	add_to_list(glowa, "Audi", "R8");
	add_to_list(glowa, "Fiat", "500");
	add_to_list(glowa, "Jeep", "Cherokee");

	print_all_cars2(glowa, 1000);
	
	delete_list(glowa);
	return 21;


}
