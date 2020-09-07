#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person 
{
	public:
		Person(string n = " ", short pop = 0, Person* b = NULL);
		void set_name(string n);
		string get_name();
		
		void set_pop(short pop);
		short get_pop();
		
		void set_bff(Person* bff);
		string get_bff();
		
	private:
		string name;
		short popularity;
		Person* bestie;
};

Person::Person(string n, short pop, Person* b):
	name(n), popularity(pop), bestie(b)
	{
		
	}
	
void Person::set_name(string n)
{
	name = n;
}

string Person::get_name()
{
	return name;
}

void Person::set_pop(short pop)
{
	popularity = pop;
}

short Person::get_pop()
{
	return popularity;
}

void Person::set_bff(Person* b)
{
	Person::bestie = b;
}

string Person::get_bff()
{
	return bestie -> get_name();
}

int main()
{
	cout << "How many friends will you list?" << endl;
	short len;
	vector<Person*> objPerVector;
	cout << "Please enter the list of friend name's" << endl;
	for (short i = 0; i < len; ++i)
	{
		string input;
		cin >> input;
		objPerVector.push_back(new Person (input));
	}
	
	for (short i = 0; i < len; ++i)
	{
		cout << "Who is " << objPerVector[i] -> get_name() << "'s friend";
		string name;
		cin >> name;
	}
	
	return 0;
}
