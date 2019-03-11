#include <iostream>
#include <memory>
#include <string>

 

using namespace std;

class Mouse
{
	string name;
public:
	bool isAlive;
	Mouse() { isAlive = true; }
	Mouse(string name) { this->name = name; isAlive = true; }
	~Mouse() {}
	string getName() { return name; }

};

struct List
{
	unique_ptr<Mouse> mysz;
	shared_ptr<List> next;
	weak_ptr<List> prev;
};


class Snake
{
public:
	
	Snake(){}
	~Snake(){}
	void bite(shared_ptr<List> head, int index)
	{
		int i = 0;
		for ( ; i < index && head != nullptr; i++)
		{
			head = head->next;
		}
		if (i == index && head != nullptr)
		{
			head->mysz->isAlive = false;
		}
		else
		{
			throw invalid_argument("Nie znaleniono myszy");
		}
	}
};


void insertList(shared_ptr<List> & head, unique_ptr<Mouse> & m)
{
	shared_ptr<List> _new(new List);
	_new->mysz = move(m);
	if (head == nullptr)
	{
		head = _new;
		_new->next = nullptr;
		_new->prev = _new->next;
	}
	else
	{
		shared_ptr<List> tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		_new->prev = tmp;
		_new->next = nullptr;
		tmp->next = _new;
	}
}
void printList(shared_ptr<List> head)
{	
	while (head != nullptr)
	{
		cout << "Mysz " << head->mysz->getName();
		if (head->mysz->isAlive)
		{
			cout << " zyje" << endl;
		}
		else cout << " nie zyje" << endl;
		head = head->next;
	}
}
void deleteDeadMouses(shared_ptr<List> & head)
{
	shared_ptr<List> tmp = head;
	while (tmp != nullptr)
	{
		
		if (tmp->mysz->isAlive == false)
		{
			if (tmp == head) head = tmp->next;

			if(tmp->next) tmp->next->prev = tmp->prev;
			if(tmp->prev.lock()) tmp->prev.lock()->next = tmp->next;
		}
	
		tmp = tmp->next;
	}
}


int main()
{
	// Test zadan zwi¹zanych z list¹:
	unique_ptr<Mouse> mysz1(new Mouse("Kamil"));
	unique_ptr<Mouse> mysz2(new Mouse("Rafal"));
	unique_ptr<Mouse> mysz3(new Mouse("Pawel"));
	shared_ptr<List> head = nullptr;
	insertList(head, mysz1);
	insertList(head, mysz2);
	insertList(head, mysz3);

	printList(head);

	Snake snuke;
	try
	{
		snuke.bite(head, 2);
	}
	catch (invalid_argument ia)
	{
		cout << ia.what() << endl;
	}

	printList(head);

	deleteDeadMouses(head);

	printList(head);
	

	// Zadanie 9:
	shared_ptr<Snake> snake1(new Snake());
	shared_ptr<Snake> snake2;
	snake2 = snake1;

	cout << snake1.use_count() << endl;

	weak_ptr<Snake> snakew1 = snake1;
	cout << snake1.use_count() << endl;
	snake2.reset();
	cout << snake1.use_count() << endl;
	snake2 = snakew1.lock();
	cout << snake1.use_count() << endl;

	weak_ptr<Mouse> mousew1;
	{
		shared_ptr<Mouse> mouse1(new Mouse("Kamil"));
		mousew1 = mouse1;
		cout << mousew1.use_count() << " : " << mousew1._Get()->getName() << endl;
	}
	cout << mousew1.use_count() << endl;

	

	
	
	//system("pause");
	return 0;
}

