/*
 * Function.cpp
 *
 *  Created on: August 6th, 2020
 *      Author: Cristian Magana
 */

#include "Function.h"
#include <iostream>



string printPyramid(int &num)
{

	std::string result = " ";
	std::string resulttemp = "";
	std::string resulttemp2 = "";
	std::string resultBase = "";
	std::string resultFinal = "";
	std::string resultBuild = "";
	std::string *myPTR = &resultBuild;


	if (!(num >= 1000) || num == 0)
	{
		for (int i = 1; i <= num; i++)
		{

			result = std::string(num - i, ' ');

			resulttemp = std::string(2 * i + 1, '-');

			result = result + resulttemp;

			resulttemp2 =  std::string(num - i, ' ');


			std::string boxreturn;
			std::string box = "| ";
			for (int k = 0; k < i; k++)
			{
				boxreturn +=box;
			}
			resulttemp2 = resulttemp2 + boxreturn + "|\n";


			resultFinal = result + '\n' + resulttemp2; 

			*myPTR = *myPTR + resultFinal; 

		}
		
		resultBase = std::string(2 * num + 1, '-');

		*myPTR = *myPTR + resultBase;
		std::cout << *myPTR;
		
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

