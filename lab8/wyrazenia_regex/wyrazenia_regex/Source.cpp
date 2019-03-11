#include <iostream>
#include <regex>
using namespace std;
void check()
{
	string input;
	regex ex1("\\b(.)*a(.)*");

	cout << "';' means end\nGimmie a word: ";
	do
	{
		cin >> input;
		if (input == ";") break;
		else if (regex_match(input, ex1))
		{
			cout << " 'a' found!" << endl;
		}
		else
		{
			cout << " 'a' not found!" << endl;
		}
		
	} while (true);
	
}
void search(string str)
{
	regex ex2("\\b(su)\\S*");
	smatch match;
	while (regex_search(str, match, ex2))
	{
		cout << match[0] << endl;
		str = match.suffix().str();
	}
}
void change(string str)
{
	regex ex3("\\b(su)([^ ]*)");
	cout << regex_replace(str, ex3, "re$2") << " ";
}
void count_digit(string str)
{
	unsigned int counter = 0;
	regex ex4("\\d*(0|2|4|6|8)( )");
	smatch match;

	while (regex_search(str, match, ex4))
	{	

		counter++;
		str = match.suffix().str();
		
	}

	cout << "\nFound " << counter << " even numbers" << endl;
}
void count(string str, int n)
{
	unsigned int counter = 0;
	regex ex5("\\S+");
	string result_str;
	//auto end = sregex_iterator();
	for (auto i = sregex_iterator(str.begin(), str.end(), ex5); i != sregex_iterator(); i++)
	{
		smatch result = *i;
		if (result.str().size() > n) counter++;	
	}
	cout << "There are " << counter << " words longer than " << n << endl;
}
void nip(string input)
{
	regex pattern("\\S*(: )\\d{3}(-)\\d{3}(-)\\d{2}(-)\\d{2}");
   
	int fields[] = { 2,3 };
	regex_token_iterator<string::const_iterator> p1(input.begin(), input.end(), pattern), p2(input.begin(), input.end(), pattern, 1), p3(input.begin(), input.end(), pattern, fields), p_end;
	for (; p1 != p_end; ++p1)
		cout << *p1 << " ";
	cout << endl;
	for (; p2 != p_end; ++p2)
		cout << *p2 << " ";
	cout << endl;
	for (; p3 != p_end; ++p3)
		cout << *p3 << " ";
	cout << endl;
}
int main()
{
	check();
	search("subaru beczka sulivan supra czechy");
	change("subaru beczka sulivan supra czechy");
	count_digit("2 2 0 9");
	count("mama tata pawel", 4);
	nip("Nazwa fimry: 123-456-32-18");
	system("pause");
	return 21;
}