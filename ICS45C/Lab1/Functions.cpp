/*
 * Functions.cpp
 *
 *  Created on: August 6th, 2020
 *      Author: Cristian Magana 
 */

#include "Functions.h"
#include <iostream>



string printPyramid(int num)
{
	if (num < 0)
	{
		std::cout << "Negative pyramid size." << std::endl;
		return 1;
	}
	if (num == 0)
	{
		std::cout << "Invlaid pryamid size." << std::endl;
		return 1;
	}
	if (num >= 1000)
	{
		std::cout << "Pyramid size too large." << std::endl;
		return 1;

	}



	std::string result = " ";
	std::string resulttemp = "";
	std::string resulttemp2 = "";
	std::string resulttempbase = "";
	std::string resultBase = "";
	std::string resultFinal = "";
	std::string resultBuild = "";
	std::string *myPTR = &resultBuild;
	std::string baseBottom = "";
	std::string* basePTR = &baseBottom;


	if (!(num >= 1000) || num == 0)
	{
		for (int i = 1; i <= num; i++)
		{

			result = std::string(num - i+1, ' ');

			//resulttemp = std::string(i, '-');

			std::string top = "-";
			for (int m = 0; m < 2*i-1 ; ++m)
			{
				resulttemp += top;
			}


			result = result + resulttemp;
			resulttemp = "";

			resulttemp2 =  std::string(num - i, ' ');


			std::string boxreturn;
			std::string box = "| ";
			for (int k = 0; k < i; k++)
			{
				boxreturn +=box;
			}
			resulttemp2 = resulttemp2 + boxreturn + "|\n";

			resultFinal = result + '\n' + resulttemp2; 

			*basePTR = result;

			*myPTR = *myPTR + resultFinal; 

		}
		if (num > 0)
		{

			//resultBase = std::string(2 * num - 1, '-');

			*myPTR = *myPTR + *basePTR;

		}
		
		//std::cout << resultBuild;
		//std::cout << *myPTR;
		
	}
	std::cout << resultBuild;
	
	return resultBuild;

}

 int getUserInput()
{
	int n;
	std::cin >> n;

	

	return n;
}

