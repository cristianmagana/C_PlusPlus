/*
 * Functions.cpp
 *
 *  Created on: August 6th, 2020
 *      Author: Cristian Magaña
 */

#include "Functions.h"
#include <iostream>

std::string rightSideBox(std::string box, int& num)
{
	std::string boxreturn;
	for (int i = 0; i < num; i++)
	{
		boxreturn += box;
	}
	return boxreturn;
}

string printPyramid(int &num)
{
	std::string result;

	for (int i = 1; i <= num; i++)
	{
		std::cout << std::string(num - i, ' ');
		for (int j = 0; j < (2 *i+1); j++)
		{
			std::cout << "-";
		}


		std::cout << std::endl;
		std::cout << std::string(num -i, ' ');

		std::cout << rightSideBox("| ", i) << "|";
		std::cout << std::endl;

	}
	
	for (int i = 1; i <= (2*num+1); i++)
	{
		std::cout << "-";
	}
	return result;
	

}

 int getUserInput()
{
	int n;
	std::cin >> n;

	if (n < 0)
	{
		cout << "Negative pyramid size." << endl;
		getUserInput();
	}
	if (n == 0)
	{
		cout <<  "Invalid pyramid size." << endl;
		getUserInput();
	}
	if (n >= 1000)
	{
		cout << "Pyramid size too large." << endl;
		getUserInput();
		
	}


	return n;
}

