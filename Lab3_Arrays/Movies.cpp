#include "Movies.h"

Movies::Movies()
{
	this->movieCode = "";
	this->movieName = "";
	this->numberOfRentedCopies = 0;

	for (int i = 0; i <= 9; i++)
	{
		this->Renters[i] = Renter();
	}
}

Movies::Movies(std::string mCode, std::string mName)
{
	this->movieCode = mCode;
	this->movieName = mName;
	this->numberOfRentedCopies = 0;

	for (int i = 0; i <= 9; i++)
	{
		//this->Renters[i] = Renter();
	}
}

std::string Movies::getMovieCode()
{
	return movieCode;
}

std::string Movies::getMovieName()
{
	return movieName;
}

int Movies::getRentedCopies()
{
	return numberOfRentedCopies;
}

void Movies::rentMovie(Renter& rentee)
{
	Exceptions f;
	try
	{
		if (numberOfRentedCopies == 9)
		{
			f.RenterLimitException();
		}
	}
	catch (std::string& f)
	{
		std::cout << "Exception occured: " << f << std::endl;
	}

			int i;
			for (i = 0; i < numberOfRentedCopies; i++)
			{
				if (Renters[i].getRenterID() == rentee.getRenterID())
				{
					f.DuplicateRenterException();
					return;
				}
			}
			if (numberOfRentedCopies == 10)
			{
				f.RenterLimitException();
			}
			else
			{

				// adds renters to renters array
				Renters[numberOfRentedCopies] = rentee;
				numberOfRentedCopies++;

				// need to sort renters array
				// Bubble Sorted by: 
				//    1. Renter.getRenterFirstName()
				//    2. Renter.getRenterLastName()
				//    3. Renter.getRenterID()

				Renter temp;
				for (int i = 1; i < numberOfRentedCopies; i++)
				{
					for (int j = 0; j < numberOfRentedCopies - i; j++)
					{
						if (Renters[j].getRenterFirstName() > Renters[j + 1].getRenterFirstName())
						{
							temp = Renters[j];
							Renters[j] = Renters[j + 1];
							Renters[j + 1] = temp;
						}
						if (Renters[j].getRenterFirstName() == Renters[j + 1].getRenterFirstName())
						{
							if (Renters[j].getRenterLastName() > Renters[j + 1].getRenterLastName())
							{
								temp = Renters[j];
								Renters[j] = Renters[j + 1];
								Renters[j + 1] = temp;
							}
						}
						if (Renters[j].getRenterFirstName() == Renters[j + 1].getRenterFirstName() && Renters[j].getRenterLastName() == Renters[j + 1].getRenterLastName())
						{
							if (Renters[j].getRenterID() > Renters[j + 1].getRenterID())
							{
								temp = Renters[j];
								Renters[j] = Renters[j + 1];
								Renters[j + 1] = temp;
							}
						}
					}
				}

	}


}


/// 
/// Need to test out the removal of Renters from the Renters array.
/// 
/// 
/// 

void Movies::returnRental(int rID)
{

	int i;
	bool renterFound = false;
	for(i = 0; i <= 9; i++)
		if (Renters[i].getRenterID() == rID)
		{
			renterFound = true;
		}
	if (i < 9)
	{
		for (int j = i; j < 9; j++)
		{
			Renters[j] = Renters[j + 1];
		}
	}
	if (Renters[9].getRenterLastName() != "")
	{
		Renters[9] = Renter();
	}
	numberOfRentedCopies--;


	// Needs to throw empty exception..
}


int Movies::getRentersID(int renteesID)
{
	bool rID_bool = false;
	for (int i = 0; i < 10; i++)
	{
		if (Renters[i].getRenterID() == renteesID)
		{
			rID_bool = true;
		}
	}
	if (rID_bool == true)
	{
		return renteesID;
	}

	else if (numberOfRentedCopies == 0)
	{
		return (renteesID * 0);
	}
		
	else
		return renteesID * 2;

}


void Movies::getRentersInfo()
{
	for (int i = 0; i <= numberOfRentedCopies; i++)
	{
		std::cout << Renters[i] << std::endl;
	}
}





ostream& operator<<(ostream& os, const Movies movie)
{
	os << "Name: " << movie.movieName << ", " << "Code: " << movie.movieCode << ", " << "Numbers of renter: " << movie.numberOfRentedCopies << "\n";

	os << "Renter(s): \n";
	for (int i = 0; i < movie.numberOfRentedCopies; i++)
	{
		os << movie.Renters[i] << "\n";
	}
	return os;
}
