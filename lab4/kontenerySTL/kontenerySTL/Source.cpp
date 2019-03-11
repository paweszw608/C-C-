#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int main()
{
	// ZADANIE A:
	deque <char> deque1({ 'x' ,'6', '3', '2', '1', '6', 'd' });
	deque <char> deque2(deque1.begin() + 1, deque1.end() - 1);
	deque2.push_back('2');
	deque2.push_front('6'); // nie ma push_front w vectorze
	deque2[2] = 'h';
	deque2.at(3) = 'e';
	cout << "A: ";
	for (int i = (deque2.size() - 1); i >= 0; --i)
		cout << deque2[i] << " ";
	cout << endl;
	// ZADANIE B:
	list <int> list1({ 6, 3, 23, 15, 6 }); 
	list1.push_back(12);
	list1.push_front(6);

	list <int>::iterator i = list1.begin();
	for (; i!=list1.end(); ++i)
	{
		if(*i == 6) list1.insert(i, 9);
	}

	i = list1.end(); --i;
	cout << "B: list: ";
	for (; i != list1.begin(); --i)
	{
		cout << *i << " ";
	}
	cout << *list1.begin();

	// forward_list
	forward_list <int> f_list1({ 6, 3, 23, 15, 6 });
	forward_list <int>::iterator f_i = f_list1.begin();

	for (; next(f_i) != f_list1.end(); ++f_i) {}

	f_list1.insert_after(f_i, 12);
	f_list1.push_front(6);

	for (f_i = f_list1.before_begin(); next(f_i) != f_list1.end(); ++f_i)
	{
		if (*next(f_i) == 6)
		{
			f_list1.insert_after(f_i, 9); 
			f_i++;
		}
	}
	cout << endl << "forward list: ";
	for (f_i = f_list1.begin(); f_i != f_list1.end(); ++f_i)
	{
		cout << *f_i << " ";
	}
	// ZADANIE C:
	stack <char> stack1(deque2);

	cout << endl << "C: ";
	while (!stack1.empty())
	{ 
		cout << stack1.top() << " ";
		stack1.pop();
	}
	cout << endl;
	cout << "queue: ";
	queue<int, list<int>> queue1(list1);
	while (!queue1.empty())
	{
		cout << queue1.front() << " ";
		queue1.pop();
	}
	cout << endl;
	// ZADANIE D:
	cout << "set: ";
	set<int> set1({ 3,5,6,9,3,4,4,4,7 });
	for (int i = 0; i < 10; i++)
	{
		if (set1.find(i) == set1.end())
		{
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "(1:10) - set: "; 
	for (set<int>::iterator i = set1.begin(); i != set1.end(); i++) 
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << "multiset: ";
	multiset<int> multiset1(set1.begin(), set1.end());
	multiset1.insert({ 3,3,3 });

	for (set<int>::iterator i = multiset1.begin(); i != multiset1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
	

}