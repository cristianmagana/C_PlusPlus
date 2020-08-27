#include "Movie.h"

int main()
{
	Movie mynewMovie;
	mynewMovie.setMovieTitle("Harry Potter and the Goblet of Fire");
	mynewMovie.setMovieYearOut(2000);
	mynewMovie.setMovieTime(330);
	mynewMovie.setMoviePrice(19.99);
	mynewMovie.movieDirector.setFirstName("J.K");
	mynewMovie.movieDirector.setLastName("Rowling");
	mynewMovie.movieDirector.setBirthYear(1965);
	mynewMovie.movieDirector.setNumOfMovies(7);
	mynewMovie.printMovieInfo();

	Movie myCopiedMovie(mynewMovie);
	myCopiedMovie.movieDirector.setNumOfMovies(8);
	myCopiedMovie.printMovieInfo();


	return 0;
}
