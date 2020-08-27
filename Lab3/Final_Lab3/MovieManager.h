// By: Cristian Magana
// ID 37578770


#ifndef MOVIEMANAGER_H_
#define MOVIEMANAGER_H_

#include "MovieManagerUI.h"
#include<limits>

class MovieManager {

private:
		Movies MoviesArray[20];
		int numberOfAvailableMovies = 0;

public:
		MovieManager();
		void run();
		void addMovie(Movies movie);
		void discontinueMovie(std::string mCode);
		void rentMovie(std::string mCode, Renter rentee);
		void returnRental(int rID, std::string mCode);
		void printInventory();

};




#endif
