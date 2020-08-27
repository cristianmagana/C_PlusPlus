#include <exception>
#include <string>
#include <iostream>
using namespace std;

class Exceptions
{
public:
	Exceptions()  {}
	~Exceptions() {}

	void DuplicateMovieException() { throw(std::string("Movie already exists"));} //Thrown when a movie already exists when trying to add a new movie.
	void MovieLimitException() { throw(std::string("Movie rental is at capacity")); } // Thrown when a movie is trying to be addedand the number of movies is at the at the max(I.e. 20).
	void EmptyMovieInfoException() { throw(std::string("Movie code and/or movie name is empty")); } // Thrown when the movie codeand /or movie name is empty when trying to add one to the movie array.
	void MovieNotFoundException() { throw(std::string("Movie does not exist")); } // Thrown when trying to do something with movie that does not exist.
	void EmptyMovieListException() { throw(std::string("Movie invnetory is already empty, unable to discontinue")); }// Thrown when trying to discontinue a movie when the inventory list is empty.
	void EmptyRenterListException() { throw(std::string("You are trying to return a movie that has no renters")); } // Thrown when trying to return a movie that does not have any copies currently being rented.
	void RenterLimitException() { throw(std::string("There are no more availble movies of this title available to rent")); }// Thrown when a renter is renting to a movie without any available copies.
	void DuplicateRenterException() { throw(std::string("Renter ID already exists")); } // Thrown when trying to add a renter to a movieand a duplicate renter ID exists.
	void RenterNotFoundException() { throw(std::string("Renter does not exist for this movie")); } // Thrown when trying to remove a renter for a movie that doesn’t exist.
	void InvalidRenterIDException() { throw(std::string("Invalid Renter ID")); } // Thrown when the user enters an invalid renter ID.
	void EmptyRenterNameException() { throw(std::string("Renter first or last name is empty")); } // Thrown when the user enters an empty firstand /or last name for the renter.
	
	void RentedMovieException() { throw(std::string("There are currently movies rented out, unable to discontinue")); } // Thrown when the user attempts to discontinue a movie that has copies currently rented out.

	

};

