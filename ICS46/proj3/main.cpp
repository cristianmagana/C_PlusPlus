/*

Jonathan Jin
SID# 17363386
UCINETID: jonathj

Cristian Magana
SID# 37578770
UCINETID: crmagan1

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

#include "proj3.hpp"
#include "Wordset.hpp"

using namespace std; 

int main()
{
	WordSet words;
	ifstream in("words.txt");
	loadWordsIntoTable(words, in);
	cout << "number of strings: " << words.getCount() << endl;
	cout << "get capacity of list 7: " << words.getCapacity() << endl;


	cout << "contains string: " << words.contains("knt") << endl;
	cout << "contains string: " << words.contains("ent") << endl;
	cout << "contains string: " << words.contains("jnt") << endl;
	cout << "contains string: " << words.contains("mnt") << endl;


	std::string r = convert("ant", "eat", words);

	cout << "convert: " << r << endl;


    return 0;
}

