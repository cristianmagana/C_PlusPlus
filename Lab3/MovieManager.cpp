// By: Cristian Magana
// ID 37578770


#include "MovieManager.h"

MovieManager::MovieManager()
{
	this->numberOfAvailableMovies = 0;
}

void MovieManager::run()
{

	// The navigator of the application.
	// This provides the different options for the application. 

	MovieManagerUI mmUI;
	mmUI.printMenu();
	std::string command = mmUI.getCommand();
	bool runProgram = true;

	if (command == "AM")
	{
		std::string movieCode = mmUI.getMovieCode();
		std::string movieName = mmUI.getMovieName();
		addMovie(Movies(movieCode, movieName));
	}



	// Discontinues movie from movie array. If not movies present, throws exception. If rented copies are out it throws an exception.
	else if (command == "DM")
	{
<<<<<<< HEAD

			bool movieFound = false;
			std::string movieCode = mmUI.getMovieCode();
			discontinueMovie(movieCode);
=======
		bool movieFound = false;
		std::string movieCode = mmUI.getMovieCode();
		discontinueMovie(movieCode);
		return;
>>>>>>> 04246003985202282184a82bef409059696ef535
	}


	// return movie. checks if renterIDs match if not throws exception. if movie doesnt exist in movie array it throws an exception.
	// aslo does a buble sort on the array when movies are returned. 

	else if (command == "RM")
	{
		int renterID = mmUI.getRenterID();
		std::string movieCode = mmUI.getMovieCode();
		std::string renterFirstName = mmUI.getRenterFirstName();
		std::string renterLastName = mmUI.getRenterLastName();
		rentMovie(movieCode, Renter(renterID, renterFirstName, renterLastName));
	}
			
	else if (command == "RR")
	{
		int renterID = mmUI.getRenterID();
		bool isPos = true;
		std::string movieCode = mmUI.getMovieCode();
		bool movieFound = false;
		returnRental(renterID, movieCode);
	}

	//print the inventory
	else if (command == "P")
	{
		printInventory();
	}

	// quits the program
	else if (command == "Q")
	{
		exit(0);
	}
}

void MovieManager::addMovie(Movies movie)
{
	for (int i = 0; i < 20; i++)
	{
		if (MoviesArray[i].getMovieCode() == movie.getMovieCode())
		{
			throw DuplicateMovieException();
		}
	}
	if (numberOfAvailableMovies == 20)
	{
		throw MovieLimitException();
	}
	else {
		MoviesArray[numberOfAvailableMovies] = movie;
		numberOfAvailableMovies++;
	}
	}
		


void MovieManager::discontinueMovie(std::string mCode)
{

	
	for (int i = 0; i < 20; i++)
		if (MoviesArray[i].getMovieCode() == mCode)
		{
			if (MoviesArray[i].getRentedCopies() != 0)
			{
				throw RentedMovieException();
			}
			break;
		}
	if (numberOfAvailableMovies == 0)
	{
		throw EmptyMovieListException();
	}

	if (i < 20)
	{
		int j;
		for (j = i; j < 18; j++)
		{
			MoviesArray[j] = MoviesArray[j + 1];
		}
	}

	if (MoviesArray[19].getMovieCode() != "" || MoviesArray[19].getMovieName() != "")
	{
		MoviesArray[19] = Movies();
	}
	numberOfAvailableMovies--;
	if (numberOfAvailableMovies < 0)
	{
		numberOfAvailableMovies = 0;
	}


}


void MovieManager::rentMovie(std::string mCode, Renter rentee)
{
	bool movieFound = false;
	int i;
	for (i = 0; i < 20; i++)
		
	{
		if (MoviesArray[i].getMovieCode() == mCode)
		{
			movieFound = true;
			if (MoviesArray[i].getRentedCopies() == 10)
			{
				throw RenterLimitException();
			}
			else
			{
				MoviesArray[i].rentMovie(rentee);
			}

		}
	}
	if (movieFound == false)
	{
		throw MovieNotFoundException();
	}

}


void MovieManager::returnRental(int rID, std::string mCode)
{	
	if (rID < 1)
	{
		throw InvalidRenterIDException();
	}

	for (int i = 0; i < 20; i++)
		if (MoviesArray[i].getMovieCode() == mCode)
		{
			
			if (MoviesArray[i].getRentedCopies() == 0)
			{
				throw EmptyRenterListException();
			}
			if (MoviesArray[i].getRentersID(rID) != rID)
			{
				throw RenterNotFoundException();
			}
			else {
				MoviesArray[i].returnRental(rID);
			}
			
		}
}

void MovieManager::printInventory()
{
	for (int i = 0; i < numberOfAvailableMovies; i++)
	{
		std::cout << MoviesArray[i];
	}
}
