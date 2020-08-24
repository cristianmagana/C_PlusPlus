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
	Exceptions e;
	Exceptions d;
	Exceptions f;
	bool runProgram = true;

	if (command == "AM")
	{
		try {

			std::string movieCode = mmUI.getMovieCode();
			std::string movieName = mmUI.getMovieName();
			if (movieCode.empty() == true || movieName.empty() == true)
			{
				e.EmptyMovieInfoException();
			}

			for (int i = 0; i < 20; i++)
			{
				if (MoviesArray[i].getMovieCode() == movieCode || MoviesArray[i].getMovieName() == movieName)
				{

					e.DuplicateMovieException();
				}
				else
				{
					continue;
				}
			}
			if (numberOfAvailableMovies == 20)
			{
				e.MovieLimitException();
				return;
			}

			Movies newMovie = Movies(movieCode, movieName);
			addMovie(newMovie);
		}
		catch (std::string& e)
		{
			std::cout << "Exception occured: " << e << std::endl;
		}
	}

	else if (command == "DM")
	{

		try
		{
			bool movieFound = false;

			std::string movieCode = mmUI.getMovieCode();
			int i;
			for (i = 0; i < 20; i++)
			{
				if (MoviesArray[i].getMovieCode() == movieCode)
				{
					movieFound = true;
					break;
				}
			}

			for (i = 0; i < 20; i++)
			{
				if (MoviesArray[i].getMovieCode() == movieCode && MoviesArray[i].getRentedCopies() == 0)
				{
					discontinueMovie(movieCode);
					return;
				}
			}

			if (numberOfAvailableMovies == 0)
			{
				e.EmptyMovieListException();
				return;
			}

			for (i = 0; i < 20; i++)
			{
				if (MoviesArray[i].getMovieCode() == movieCode && MoviesArray[i].getRentedCopies() > 0)
				{
					e.RentedMovieException();
					return;
				}
				else
				{
					//e.MovieNotFoundException();
				}

			}
		}

		catch (std::string& e)
		{
			std::cout << "Exception occured: " << e << std::endl;
		}

	}

	else if (command == "RM")
	{

		int renterID = mmUI.getRenterID();
		bool isPos = true;

		try
		{			
			if (renterID < 0)
			{
				isPos = false;
				f.InvalidRenterIDException();
				
			}
		}
		catch (std::string& f)
		{
			std::cout << "Exception occured: " << f << std::endl;

		}
		if (isPos == true)
		{
			try
			{
				std::string movieCode = mmUI.getMovieCode();
			
				std::string renterFirstName = mmUI.getRenterFirstName();
				std::string renterLastName = mmUI.getRenterLastName();
				bool rent = false;
				for (int i = 0; i < 20; i++)
				{
					if (MoviesArray[i].getMovieCode() == movieCode)
					{
						Renter rentee = Renter(renterID, renterFirstName, renterLastName);
						rentMovie(movieCode, rentee);
						rent = true;
					}
				}
				if (rent == false)
				{
					e.MovieNotFoundException();
				}
			}
			catch (std::string& e)
			{
				std::cout << "Exception occured: " << e << std::endl;
			}
		}
	}

	


	else if (command == "RR")
	{
		int renterID = mmUI.getRenterID();

		bool isPos = true;

		try
		{
			if (renterID < 0)
			{
				isPos = false;
				f.InvalidRenterIDException();

			}
		}
		catch (std::string& f)
		{
			std::cout << "Exception occured: " << f << std::endl;

		}


		if (isPos == true)
		{

			std::string movieCode = mmUI.getMovieCode();
			bool movieFound = false;
			try
			{
				for (int i = 0; i < 20; i++)
				{
					if (MoviesArray[i].getMovieCode() == movieCode)
					{
						movieFound = true;
					}
				}
				if (movieFound == false)
				{
					e.MovieNotFoundException();
				}
			}
			catch (std::string& e)
			{
				std::cout << "Exception occured: " << e << std::endl;
			}
			
			try
			{	
				int i;
				bool renterMovie = false;
				for (i = 0; i < 20; i++)
				{
					if (MoviesArray[i].getRentersID(renterID) == renterID)
					{
						renterMovie = true;
					}
				}
				if (renterMovie == true)
				{
					returnRental(renterID, movieCode);
					return;
				}
				
				bool renterNotFound = false;
				for (i = 0; i < 20; i++)
				{
					if (MoviesArray[i].getRentersID(renterID) == (renterID * 2))
					{
						renterNotFound = true;
					}
				}
				if (renterNotFound == true)
				{
					d.RenterNotFoundException();
					return;
				}

				bool renterIsEmpty = false;
				for (i = 0; i < 20; i++)
				{
					if (MoviesArray[i].getRentersID(renterID) *0 == (renterID * 0))
					{
						renterIsEmpty = true;
					}
				}
				if (renterIsEmpty == true)
				{
					d.EmptyRenterListException();
				}	
			}
			catch (std::string& d)
			{
				std::cout << "Exception occured: " << d << std::endl;
			}
		}	
	}

	else if (command == "P")
	{
		printInventory();
	}


	else if (command == "Q")
	{

		exit(0);
	}
}

void MovieManager::addMovie(Movies &movie)
{
		MoviesArray[numberOfAvailableMovies] = movie;
		numberOfAvailableMovies++;
}


void MovieManager::discontinueMovie(std::string mCode)
{
	int i;
	for (i = 0; i < 20; i++)
		if (MoviesArray[i].getMovieCode() == mCode)
		{
			break;
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

	


	// Needs to throw empty exception..
}


void MovieManager::rentMovie(std::string mCode, Renter& rentee)
{
	
	int i;
	for (i = 0; i < 20; i++)
		if (MoviesArray[i].getMovieCode() == mCode)
		{
			MoviesArray[i].rentMovie(rentee);
		}

}


void MovieManager::returnRental(int rID, std::string mCode)
{	
	for (int i = 0; i < 20; i++)
		if (MoviesArray[i].getMovieCode() == mCode)
		{
			MoviesArray[i].returnRental(rID);
		}
}



void MovieManager::printInventory()
{
	for (int i = 0; i < numberOfAvailableMovies; i++)
	{
		std::cout << MoviesArray[i] << std::endl;
	}
}
