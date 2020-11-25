/*

Jonathan Jin
SID# 17363386
UCINETID: jonathj

Cristian Magana
SID# 37578770
UCINETID: crmagan1

*/

#include "Wordset.hpp"
#include <string>
#include <map>
#include <iostream>
#include <cmath>

const int BASE_TO_USE = 41; 
const double LOAD_LIMIT = 0.27;
std::map<char,unsigned> mapping = { {'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7},{'i',8},{'j',9},{'k',10},{'l',11},{'m',12},{'n',13},{'o',14},{'p',15},{'q',16},{'r',17},{'s',18},
{'t',19},{'u',20},{'v',21},{'w',22},{'x',23},{'y',24},{'z',25}};

// returns s, as a number in the given base, mod the given modulus
int hashFunction(std::string s, int base, int mod)
{
	unsigned s_len = s.length();
	unsigned power = s.length() -1;
	unsigned s_num = 0;

	for(int i = 0; i <= s_len -1; i++)
    {
		int expon = pow (base,power);
    	s_num += mapping[s[i]] * expon ;
		power--;
    }

	s_num %=  mod;
	return s_num; 
}

// constructor - allocates dynamic array of SIZES[] using a t_size int that will increment++ given inserts
//               all indexes set to " ".
WordSet::WordSet()
{
	table = new std::string[SIZES[t_size]];

	for(int i = 0; i < SIZES[t_size]; i++)
	{
		table[i] = " ";
	}
}

// deconstructor - deletes memeory allocation for *table[];
WordSet::~WordSet()
{
	delete[] table;
}

// allocates a newTable pointer, 
//     rehashes the contents of the old table, 
//         deletes the old table
//            re-points newTable to be table.
void WordSet::resize()
{
	//Increments to next prime in SIZES[]
	t_size++;

	//Creates the new table with next prime in SIZES[] -- Fills with blanks
	std::string *newTable = new std::string[SIZES[t_size]];
	for(int i = 0; i < SIZES[t_size]; i++)
	{
		newTable[i] = " ";
	}

	//Copy elements from table to newTable
	//deletes old table pointer and points table to be newTable
	for(int i = 0; i < SIZES[t_size-1]; i++)
	{
		if(table[i] != " ")
		{
			int pos = hashFunction(table[i], BASE_TO_USE, SIZES[t_size]);
			int h = 1; 
			while (newTable[pos] != " ")
			{	
				pos = (pos + (h*h)) % SIZES[t_size];
			}
			newTable[pos] = table[i];
		}
	}
	delete[] table;
	table = newTable;
}

// return the current threshold for the hash table
float WordSet::getThresh()
{
	threshold = (float)(n_o_inserts +1) / (float)(SIZES[t_size]);

	return threshold;
}

void WordSet::insert(std::string s)
{
	//Forces RESIZE() if the the next addition will put it over the threshold. 
	
	if(getThresh() > LOAD_LIMIT)
	{
		resize();
	}

	// Insert Alogrithm w/ Quadratic Probing
	int temp = hashFunction(s, BASE_TO_USE,SIZES[t_size]);
	int i = temp, h = 1;
	do
	{
		if(table[i] == " ")
		{
			table[i] = s;
			n_o_inserts++;
			return;
		}
		if(table[i] == s)
		{
			table[i] = s;
			return;
		}
		i = (i + h * h) % SIZES[t_size];
		h++;
	} while (i != temp);


}

// checks if an element is contained within the hash table. 
//     takes in a string, calaculates the hash key, and checks that position. 
bool WordSet::contains(std::string s) const
{
	int pos = hashFunction(s,BASE_TO_USE,SIZES[t_size]);
	
	if(table[pos] == s)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// prints the hash table 
void WordSet::printHashTable()
{
	for(int i = 0; i < SIZES[t_size]; i++)
	{
		std::cout << i << ": " << table[i] << std::endl;
	}
}

// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return n_o_inserts;
}

// return how large the underlying array is.
int WordSet::getCapacity() const
{
	return SIZES[t_size];
}

































	
	/*
	threshold = n_o_inserts / getCapacity(); 

	if(threshold >= LOAD_LIMIT)
	{	
		t_size++;
		std::string * temp = new std::string[t_size];
		for(int i = 0; i < SIZES[t_size]; i++)
		{
			temp[i] = '0';
		}
		
		for(int i = 0; i < SIZES[t_size -1]; i++)
		{
			std::string s_temp = table[i];
			int pos = hashFunction(s_temp,BASE_TO_USE,SIZES[t_size]);
			temp[pos] = s_temp; 
		}
	}*/