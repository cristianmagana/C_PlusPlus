/*
 * Function.cpp
 *
 *  Created on: August 6th, 2020
 *      Author: Cristian Magana
 */

#include "Function.h"
#include <iostream>

/*std::string rightSideBox(std::string box, int &num)
{
	std::string boxreturn;
	for (int i = 0; i < num; i++)
	{
		boxreturn += box;
	}
	return boxreturn;
}
*/

string printPyramid(int &num)
{

	std::string result = " ";
	if (!(num >= 1000) || num == 0)
	{
		for (int i = 1; i <= num; i++)
		{

			std::cout << std::string(num - i, ' ');
			for (int j = 0; j < (2 * i + 1); j++)
			{
				std::cout << "-";
			}

			std::cout << std::endl;
			std::cout << std::string(num - i, ' ');


			std::string boxreturn;
			std::string box = "| ";
			for (int k = 0; k < i; k++)
			{
				boxreturn +=box;
			}
			std::cout << boxreturn << "|";

			//std::cout << rightSideBox("| ", i) << "|";
			std::cout << std::endl;

		}
	}
	if (num != 0 && num < 1000)
	{
		for (int i = 1; i <= (2 * num + 1); i++)
		{
			std::cout << "-";
		}
	}


	
	return result;

}

 int getUserInput()
{
	int n;
	std::cin >> n;

	if (n < 0)
	{
		std::cout << "Negative pyramid size." << std::endl;
	}
	if (n == 0)
	{
		std::cout << "Invlaid pryamid size." << std::endl;
	}
	if (n >= 1000)
	{
		std::cout << "Pyramid size too large." << std::endl;
	}

	return n;
}

