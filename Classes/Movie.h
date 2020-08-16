#ifndef MOVIE_H_
#define MOVIE_H_

#include "Director.h"


class Movie {
private:
	int duration;
	int yearOfRelease;
	std::string priceofMovie;
	std::string titleOfMovie;


public:
	Director movieDirector;
	// Default Constructor
	Movie(); 
	Movie(int movieDuration, int moiveYear, std::string movieCost, std::string movieTitle); 
	Movie(Movie &Movie); 
	void setMovieTime(int movieDuration);
	int getMovieTime();
	void setMovieYearOut(int movieYear);
	int getMovieYearOut();
	void setMoviePrice(std::string movieCost);
	std::string getMoviePrice();
	void setMovieTitle(std::string movieTitle);
	std::string getMovieTitle();
	void printMovieInfo();


}; 



#endif 
