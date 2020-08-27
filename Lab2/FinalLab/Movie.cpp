#include "Movie.h"

Movie::Movie() {
	this->movieDirector = Director();
	this->duration = 0;
	this->priceofMovie = 00.00;
	this->titleOfMovie = " ";
	this->yearOfRelease = 0000;
}




Movie::Movie(int durationOfMovie, int ReleaseYear, double MoviePrice, std::string MovieTitle,
	std::string DirectorFirstName, std::string DirectorLastName, int DirectorYearOfBirth, int NumberOfFilmsForTheDirector)
{
	this->duration = durationOfMovie;
	this->yearOfRelease = ReleaseYear;
	this->priceofMovie = MoviePrice;
	this->titleOfMovie = MovieTitle;
	this->movieDirector.setFirstName(DirectorFirstName);
	this->movieDirector.setLastName(DirectorLastName);
	this->movieDirector.setBirthYear(DirectorYearOfBirth);
	this->movieDirector.setNumOfMovies(NumberOfFilmsForTheDirector);

}

Movie::Movie(Movie &movie)
{
	this->movieDirector = movie.movieDirector;
	this->duration = movie.getMovieTime();
	this->priceofMovie = movie.getMoviePrice();
	this->titleOfMovie = movie.getMovieTitle();
	this->yearOfRelease = movie.getMovieYearOut();
}


void Movie::setMovieTime(int DurationOfMovie)
{
	this->duration = DurationOfMovie;
}

int Movie::getMovieTime()
{
	return this->duration;
}

void Movie::setMovieYearOut(int ReleaseYear)
{
	this->yearOfRelease = ReleaseYear;
}

int Movie::getMovieYearOut()
{
	return this->yearOfRelease;
}

void Movie::setMoviePrice(double MoviePrice)
{
	this->priceofMovie = MoviePrice;
}

double Movie::getMoviePrice()
{
	return this->priceofMovie;
}

void Movie::setMovieTitle(std::string MovieTitle)
{
	this->titleOfMovie = MovieTitle;
}

std::string Movie::getMovieTitle()
{
	return this->titleOfMovie;
}

void Movie::printMovieInfo()
{
	std::cout << "Title: " << this->titleOfMovie << std::endl;
	std::cout << "\n";
	std::cout << "Published in: " << this->yearOfRelease << std::endl;
	std::cout << "\n";
	std::cout << "Duration of Movie: " << this->duration <<" minutes" << std::endl;
	std::cout << "\n";
	std::cout << "Price: " <<"$" << this->priceofMovie << std::endl;
	std::cout << "\n";
	std::cout << "Directed by " << movieDirector.getFirstName()<<" "<< movieDirector.getLastName() << ","<< " who was born in " << movieDirector.getBirthYear()  << " and has " << movieDirector.getNumOfMovies() << " releases." << std::endl;
	std::cout << "\n";
}

