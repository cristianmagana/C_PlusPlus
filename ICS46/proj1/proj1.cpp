#include "proj1.hpp"
#include <map>
#include <string>
#include <list>
#include <iterator>
#include <iostream>

bool checkSolution(std::string& s1, std::string &s2, std::string &s3, std::map<char, unsigned> & mapping)
{
	unsigned int s1_len = s1.length();
    unsigned int s2_len = s2.length();
    unsigned int s3_len = s3.length();
    unsigned int s1_num = 0;
    unsigned int s2_num = 0;
    unsigned int s3_num = 0;
	
	for(int i = 0; i <= s1_len -1; i++)
    {
        s1_num = 10 * s1_num + mapping.at(s1[i]);
    }

    for(int i = 0; i <= s2_len -1; i++)
    {
        s2_num = 10 * s2_num + mapping.at(s2[i]);
    }
  
    for(int i = 0; i <= s3_len -1; i++)
    {
        s3_num = 10 * s3_num + mapping.at(s3[i]);
    }
	
	if(s1_num + s2_num == s3_num)
    {
		return true;
    }
	else
	{
		return false;
	}
	
}

/* Recursion function that tries the permutations of letters to digits*/

void puzzleRecursion(int k, int &solnCount, std::list<char> &L,std::list<unsigned> &S, std::list<unsigned> &U,std::string &s1, std::string &s2, std::string &s3, std::map<char, unsigned> & mapping)
{	
	mapping.clear(); // Clears map on every iteration

	// For every distinct letter in L, it will apply a 0-9 from S.
	// Makes pairs in maps based on the above. 

	for(int i = 0; i < L.size()  ; i++)
	{
		auto it = S.begin();
		auto itL = L.begin();
		std::advance(it,i);
		std::advance(itL,i);
		mapping.insert(std::make_pair(char(*itL),unsigned(*it)));
	}
	
	// Algorithm from "Data Structures and Algorithms" By Michael Goodrich p.148
	// "Take one down, pass it around, only 1783842364 more beers on the wall"
	for(int i = 0; i < U.size(); i++)
	{
		auto it = U.begin();
		unsigned e = *it;
		S.push_back(e);
		U.remove(e);
		
		if (k==1)
		{
			if(checkSolution(s1,s2,s3,mapping) == true)
				{
					solnCount++;
					return;
				}	
		}	
		else 
		{
			puzzleRecursion((k-1),solnCount,L,S,U,s1,s2,s3,mapping);
		}
		if(checkSolution(s1,s2,s3,mapping) == true) // Have to check solution twice so it does not alter the map. 
		{
			return;
		}	

		it = U.end();
		S.remove(e);
		U.push_back(e);
	}
}
void distincLetters(std::string&puzzle, std::list<char> &L)
{
	// Adds Distict Letters List L: eg. POT + PAN = BIB -> POTANIB
		bool uChar = false;
		for(int i = 0; i < puzzle.length(); i++)
		{
			char tempChar = puzzle[i];
			bool found = (std::find(L.begin(), L.end(), tempChar) != L.end());
			for(int j = i + 1; j < puzzle.length(); j++)
				if(puzzle[i] == puzzle[j])
				{
					uChar = false;
				}
				else
				{
					uChar = true;
				}
			
			if(uChar == true & found != true)
			{
				L.push_back(tempChar);
			}
		}
}

bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	std::string puzzle = s1+s2+s3;
	std::list<unsigned> U; 
	std::list<unsigned> S;
	std::list<char> L; 
	int solnCount = 0;

	// Create set of unsigned ints 0,1,2...9 in list U
	for(unsigned i = 0; i < 10; i++)
	{
		U.push_back(i);
	}

	distincLetters(puzzle,L);
	
	// Checks if there are more than 10 different letters in the puzzle, if so return false. 
	if(L.size() > 10)
	{
		return false;
	}

	puzzleRecursion(L.size()+1,solnCount,L,S,U, s1,s2,s3,mapping);

	if(solnCount > 0)
	{
		return 1;
	}
	else if( solnCount <= 0)
	{
		return 0;
	}
	return true;
}


