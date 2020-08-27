#include "Movie.h"

Movie::Movie() {
	this->duration = 0;
	this->priceofMovie = "$ 00.00";
	this->titleOfMovie = " ";
	this->yearOfRelease = 0000;

}

Movie::Movie(Movie& Movie)
{
	this->duration = Movie.getMovieTime();
	this->priceofMovie = Movie.getMoviePrice();
	this->titleOfMovie = Movie.getMovieTitle();
	this->yearOfRelease = Movie.getMovieYearOut();
}



Movie::Movie(int movieDuration, int movieYear, std::string movieCost, std::string movieTitle)
{
	this->duration = movieDuration;
	this->priceofMovie = movieCost;
	this->titleOfMovie = movieTitle;
	this->yearOfRelease = movieYear;
}

void Movie::setMovieTime(int movieDuration)
{
	this->duration = movieDuration;
}

int Movie::getMovieTime()
{
	return this->duration;
}

void Movie::setMovieYearOut(int movieYear)
{
	this->yearOfRelease = movieYear;
}

int Movie::getMovieYearOut()
{
	return this->yearOfRelease;
}

void Movie::setMoviePrice(std::string movieCost)
{
	this->priceofMovie = movieCost;
}

std::string Movie::getMoviePrice()
{
	return this->priceofMovie;
}

void Movie::setMovieTitle(std::string movieTitle)
{
	this->titleOfMovie = movieTitle;
}

std::string Movie::getMovieTitle()
{
	return this->titleOfMovie;
}

void Movie::printMovieInfo()
{
	std::cout << "Title: " << this->titleOfMovie << std::endl;
	std::cout << "Published in: " << this->yearOfRelease << std::endl;
	std::cout << "Duration of Movie: " << this->duration <<" minutes" << std::endl;
	std::cout << "Directed by " << movieDirector.getFirstName()<<" "<< movieDirector.getLastName() << " who was born in " << movieDirector.getBirthYear()  << " and has " << movieDirector.getNumOfMovies() << " releases." << std::endl;

}

