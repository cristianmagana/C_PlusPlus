#include "MovieManagerUI.h"

void MovieManagerUI::printMenu()
{

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Welcome to Movie Rental Kiosk!" << std::endl;
	std::cout << "am: Add Movie" << std::endl;
	std::cout << "dm : Discontinue Movie" << std::endl;
	std::cout << "rm : Rent Movie" << std::endl;
	std::cout << "rr : Return Rental" << std::endl;
	std::cout << "p : Print Movie Inventory" << std::endl;
	std::cout << "q : Quit Program" << std::endl;

}
std::string MovieManagerUI::getCommand()
{
	std::string input;
	std::cin >> input;
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);
	return input;
}

std::string MovieManagerUI::getMovieName()
{
	
	std::cout << "Provide the Movie Name: " << std::endl;
	std::string movieName = "";
	std::cin.ignore();
	std::getline(std::cin, movieName, '\n');
	std::transform(movieName.begin(), movieName.end(), movieName.begin(), ::toupper);
	return  movieName;
}

std::string MovieManagerUI::getMovieCode()
{
	std::string movieCode;
	std::cout << "Provide the Movie Code: " << std::endl;
	std::cin >> movieCode;
	if (movieCode == "")
	{
		std::cout << "Please enter a valid Movie Code" << std::endl;
		getMovieName();
	}
	else
		std::transform(movieCode.begin(), movieCode.end(), movieCode.begin(), ::toupper);
		return movieCode;
}

int MovieManagerUI::getRenterID()
{
	int renterID;
	std::cout << "Provide the Renter ID: " << std::endl;
	std::cin >> renterID;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		renterID = -1;
	}
	return renterID;
	
}

std::string MovieManagerUI::getRenterFirstName()
{
	std::string renterFirstName;
	std::cout << "Provide the Renter First Name: " << std::endl;
	std::cin >> renterFirstName;
	if (renterFirstName == "")
	{
		std::cout << "Please enter a valid Renter First Name" << std::endl;
		getRenterFirstName();
	}
	else 
		std::transform(renterFirstName.begin(), renterFirstName.end(), renterFirstName.begin(), ::toupper);
		return renterFirstName;
}

std::string MovieManagerUI::getRenterLastName()
{
	std::string renterLastName;
	std::cout << "Provide the Renter Last Name: " << std::endl;
	std::cin >> renterLastName;
	if (renterLastName == "")
	{
		std::cout << "Please enter a valid Renter Last Name" << std::endl;
		getRenterLastName();
	}
	else
		std::transform(renterLastName.begin(), renterLastName.end(), renterLastName.begin(), ::toupper);
		return renterLastName;
}

//toUpper(command)
