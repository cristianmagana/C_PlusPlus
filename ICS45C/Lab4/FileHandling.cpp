// Cristian Magana 
// 37578770
// File Handling class takes in user input of file name, appends the ".txt", requests the size of the pyramid to be printed and utilizes ostream and ofstream to write the pryamid to the file. 

#include "FileHandling.h"

FileHandling::FileHandling() 
{
	this->fName = "";
	this->pSize = 0;
}

void FileHandling::setFileName(std::string fileNameIn)
{
	fileNameIn += ".txt";
	this->fName = fileNameIn;
}

void FileHandling::setNumberOfPyramid(int pSizeIn)
{
	this->pSize = pSizeIn;
}

std::string FileHandling::printPyramid(int num)
{
	ofstream sout;
	std::string fileNameIn = this->fName;
	sout.open(fileNameIn);

	if (num < 0)
	{
		sout << "Negative pyramid size.";
		return "Negative pyramid size.";

	}
	if (num == 0)
	{

		sout << "Invalid pyramid size.";
		return "Invalid pyramid size.";
	}
	if (num >= 1000)
	{
		sout << "Pyramid size too large.";
		return "Pyramid size too large.";
	}
	else {

		std::string result = " ";
		std::string resulttemp = "";
		std::string resulttemp2 = "";
		std::string resulttempbase = "";
		std::string resultBase = "";
		std::string resultFinal = "";
		std::string resultBuild = "";
		std::string* myPTR = &resultBuild;
		std::string baseBottom = "";
		std::string* basePTR = &baseBottom;

		if (!(num >= 1000) || num == 0)
		{
			for (int i = 1; i <= num; i++)
			{
				result = std::string(num - i + 1, ' ');
				std::string top = "-";
				for (int m = 0; m < 2 * i - 1; ++m)
				{
					resulttemp += top;
				}

				result = result + resulttemp;
				resulttemp = "";
				resulttemp2 = std::string(num - i, ' ');

				std::string boxreturn;
				std::string box = "| ";
				for (int k = 0; k < i; k++)
				{
					boxreturn += box;
				}
				resulttemp2 = resulttemp2 + boxreturn + "|\n";
				resultFinal = result + '\n' + resulttemp2;
				*basePTR = result;
				*myPTR = *myPTR + resultFinal;
			}
			if (num > 0)
			{
				*myPTR = *myPTR + *basePTR;
			}
		}
		sout << resultBuild;


		return resultBuild;
	}

	sout.close();
	return "";
}

std::string FileHandling::printOutPyramid()
{
	ofstream sout;
	sout.open(FileHandling::fName);
	int num = FileHandling::pSize;

	if (num < 0)
	{
		sout << "Negative pyramid size.";
		return "Negative pyramid size.";

	}
	if (num == 0)
	{
		sout << "Invalid pyramid size.";
		return "Invalid pyramid size.";
	}
	if (num >= 1000)
	{
		sout << "Pyramid size too large.";
		return "Pyramid size too large.";
	}
	else
	{
		std::string result = " ";
		std::string resulttemp = "";
		std::string resulttemp2 = "";
		std::string resulttempbase = "";
		std::string resultBase = "";
		std::string resultFinal = "";
		std::string resultBuild = "";
		std::string* myPTR = &resultBuild;
		std::string baseBottom = "";
		std::string* basePTR = &baseBottom;

		if (!(num >= 1000) || num == 0)
		{
			for (int i = 1; i <= num; i++)
			{
				result = std::string(num - i + 1, ' ');
				std::string top = "-";
				for (int m = 0; m < 2 * i - 1; ++m)
				{
					resulttemp += top;
				}

				result = result + resulttemp;
				resulttemp = "";
				resulttemp2 = std::string(num - i, ' ');

				std::string boxreturn;
				std::string box = "| ";
				for (int k = 0; k < i; k++)
				{
					boxreturn += box;
				}
				resulttemp2 = resulttemp2 + boxreturn + "|\n";
				resultFinal = result + '\n' + resulttemp2;
				*basePTR = result;
				*myPTR = *myPTR + resultFinal;
			}
			if (num > 0)
			{
				*myPTR = *myPTR + *basePTR;
			}
		}
		sout << resultBuild;

		return resultBuild;
	}


	sout.close();
	return "";
}
