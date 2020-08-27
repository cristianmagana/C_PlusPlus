#ifndef MOVIE_H_
#define MOVIE_H_

#include "Director.h"


class Movie {
private:
	int duration;
	int yearOfRelease;
	double priceofMovie;
	std::string titleOfMovie;


public:
	Director movieDirector;
	Movie(); 
	Movie(int DurationOfMovie, int ReleaseYear, double MoviePrice, std::string MovieTitle,
		std::string DirectorFirstName, std::string DirectorLastName, int DirectorYearOfBirth, int NumberOfFilmsForTheDirector); 
	Movie(Movie& movie);
	void setMovieTime(int DurationOfMovie);
	int getMovieTime();
	void setMovieYearOut(int ReleaseYear);
	int getMovieYearOut();
	void setMoviePrice(double MoviePrice);
	double getMoviePrice();
	void setMovieTitle(std::string MovieTitle);
	std::string getMovieTitle();
	void printMovieInfo();


}; 

#endif 
