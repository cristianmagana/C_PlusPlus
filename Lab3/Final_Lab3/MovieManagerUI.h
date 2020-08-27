// By: Cristian Magana
// ID 37578770

#ifndef MOVIEMANAGERUI_H_
#define MOVIEMANAGERUI_H_

#include "Movies.h"
#include <algorithm>
#include <string>
#include <sstream>

class MovieManagerUI
{
public:
	void printMenu();
	std::string getCommand();
	std::string getMovieName();
	std::string getMovieCode();
	int getRenterID();
	std::string getRenterFirstName();
	std::string getRenterLastName();
		//toUpper(command)



};

#endif
