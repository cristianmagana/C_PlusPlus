// Cristian Magana
// 37578770
// File Handling class takes in user input of file name, appends the ".txt", requests the size of the pyramid to be printed and utilizes ostream and ofstream to write the pryamid to the file. 

#ifndef FILEHANDLING_H_
#define FILEHANDLING_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandling {
private:
	std::string fName;
	int pSize;

public: 
	FileHandling();
	void setFileName(std::string fileName);
	void setNumberOfPyramid(int pSizeIn);
	std::string printPyramid(int num);
	std::string printOutPyramid();
};




#endif