#include<iostream>
#include<set>
#include<string>
int main()
{

	std::set<std::string> setOfNumbers;

	// Lets insert four elements
	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("first");

	// Iterate through all the elements in a set and display the value.
	for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
	    std::cout << ' ' << *it;

	std::cout<<std::endl;

	setOfNumbers.erase("third");

	// Iterate through all the elements in a set and display the value.
	for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
		    std::cout << ' ' << *it;

	std::cout<<std::endl;
	return 0;
}
