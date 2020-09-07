#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Person {
	public:
		Person(string n = " ", short pop = 0, Person* b = NULL);
		
		void set_n(string n);
		string get_n();
		
		void set_pop(short pop);
		short get_pop();
		
		void set_bff(Person* b);
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

void Person::set_n(string n)
{
	Person::name = n;
}

string Person::get_n()
{
	return name;
}

void Person::set_pop(short pop)
{
	popularity=pop;
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
	return bestie -> get_n();
}

int main() 
{
	cout << "How many names will you list? " << endl;
	short len;
	cin >> len;
	
	vector<Person*> pObVec;
	cout << "Please enter a list of names: " << endl;
	for(short i; i < len; ++i)
	{

		string input;
		cin >> input; 
		pObVec.push_back(new Person(input));
	}
	cout << endl;
	for(short i = 0; i < len; ++i)
	{
		cout << "Enter name of " << pObVec[i]->get_n() << "'s friend: ";
		string name;
		cin >> name;
		for(short j = 0; j < len; j++)
		{
			if(pObVec[j]->get_n() == name)
			{
				pObVec[j]->set_pop((pObVec[j]->get_pop())+1);
				pObVec[i]->set_bff(pObVec[j]);
			}
		}
	}
	cout << endl;
	for(short i = 0; i < len; i++)
	{
		cout << "name: " << setw(8) << pObVec[i]->get_n() << " popularity: " << pObVec[i]->get_pop() << " bff: " << setw(8) << pObVec[i]->get_bff() << endl;
	}
	
	for(short i = 0; i < len; i++)
	{
		delete pObVec[i];
	}

	

	return 0;
}
	
	
	
