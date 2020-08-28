// Cristian Magana
// 37578770
// File Handling class takes in user input of file name, appends the ".txt", requests the size of the pyramid to be printed and utilizes ostream and ofstream to write the pryamid to the file. 

#include "FileHandling.h"

int main()
{
	// Creates the FilingHandling object which will... 
	FileHandling fileInQuestion;

	std::string fileName = "";
	std::cin >> fileName;
	int pyramidSize;
	std::cin >> pyramidSize;
	fileInQuestion.setFileName(fileName);
	fileInQuestion.setNumberOfPyramid(pyramidSize);
	fileInQuestion.printPyramid(pyramidSize);
	fileInQuestion.printOutPyramid();


	return 0;
}