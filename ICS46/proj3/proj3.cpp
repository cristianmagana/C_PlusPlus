/*

Jonathan Jin
SID# 17363386
UCINETID: jonathj

Cristian Magana
SID# 37578770
UCINETID: crmagan1

*/


#include "proj3.hpp"
#include "Wordset.hpp"
#include <iostream>
#include <set>
#include <sstream>
#include <map>
#include <stack>
#include <queue>

#include <iostream> //self added library
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


// You should not need to change this function.
void loadWordsIntoTable(WordSet & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}
}

// You probably want to change this function.
std::string convert(std::string s1, std::string s2, const WordSet & words)
{
	map <string, string> wordSetMap; // store key=found string and value = old string
	vector<string> visited; 
	queue <string> stringQueue; 
	
	stringQueue.push(s1);
	visited.push_back(s1);
	bool found = false; 

	while (!stringQueue.empty() && found == false) {
		string current = stringQueue.front();
		stringQueue.pop();
		string temp = current; 

		for (int i = 0; i < current.size(); i++) {
			//cout << "current: " << current << endl;
			if (current[i] != s2[i]) {


				for (int alpha = 'a'; alpha <= 'z'; ++alpha) {
					if (temp[i] == alpha) {
						continue;
					}
					temp[i] = alpha; 
					//cout << "	word: " << temp << endl;

					if (words.contains(temp)) {
						//cout << "		found word: " << temp << endl;
						if (find(visited.begin(), visited.end(), temp) != visited.end()) {
							continue;
						}
						else {
							wordSetMap[temp] = current;
							//cout << "		push temp to queue: " << temp << endl;
							stringQueue.push(temp);
							visited.push_back(temp);
						}
						if (temp == s2) {
							found = true;
							break;
						}

					}

						
				}
				temp[i] = current[i];
			}

			if (found == true) {
				break;
			}

		}
	}

	//// convert map to a route string
	vector<string> route;
	bool routeFinished = false;

	route.push_back(s2);
	string lastWord = wordSetMap[s2];
	string finalReturn = "";

	while (!routeFinished) {
		if (lastWord != s1) {
			route.push_back(lastWord);
			lastWord = wordSetMap[lastWord];
		}
		else {
			route.push_back(lastWord);
			routeFinished = true;
		}
	}
	for (int i = route.size() - 1; i >= 0; i--) {
		if (i != route.size() - 1) {
			finalReturn += " --> ";
		}
		finalReturn += route[i];
	}

	return finalReturn;  // stub obviously 
}
