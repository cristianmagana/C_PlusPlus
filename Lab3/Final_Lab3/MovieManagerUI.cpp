// By: Cristian Magana
// ID 37578770


#include "MovieManagerUI.h"

void MovieManagerUI::printMenu()
{

	std::cout << "----------";
	std::cout << "\nam: Add Movie";
	std::cout << "\ndm: Discontinue Movie";
	std::cout << "\nrm: Rent Movie";
	std::cout << "\nrr: Return Rental";
	std::cout << "\np: Print Movie Inventory";
	std::cout << "\nq: Quit Program";
	std::cout << "\n----------\n";
	std::cout << "Enter Command:";

}

// Takes in command and return is as capitalized letters
std::string MovieManagerUI::getCommand()
{
	std::string input;
	std::cin >> input;
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);
	return input;
}

// Takes in and returns movie name
std::string MovieManagerUI::getMovieName()
{
	
	std::cout << "Provide the Movie Name: " << std::endl;
	std::string movieName = "";
	std::cin.ignore();
	std::getline(std::cin, movieName, '\n');
	//std::transform(movieName.begin(), movieName.end(), movieName.begin(), ::toupper);
	return  movieName;
}

// Takes in and returns movie code
std::string MovieManagerUI::getMovieCode()
{
	std::string movieCode;
	std::cout << "Provide the Movie Code: " << std::endl;
	std::cin >> movieCode;
  //std::transform(movieCode.begin(), movieCode.end(), movieCode.begin(), ::toupper);
	return movieCode;
}

// Takes in and returns renterID
int MovieManagerUI::getRenterID()
{
	int renterID;
	std::cin.clear();
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
   //std::transform(renterFirstName.begin(), renterFirstName.end(), renterFirstName.begin(), ::toupper);
    return renterFirstName;
}

std::string MovieManagerUI::getRenterLastName()
{
	std::string renterLastName;
	std::cout << "Provide the Renter Last Name: " << std::endl;
	std::cin >> renterLastName;
	//if (renterLastName == "")
	//{
		//std::cout << "Please enter a valid Renter Last Name" << std::endl;
		//getRenterLastName();
	//}
	//else
	//std::transform(renterLastName.begin(), renterLastName.end(), renterLastName.begin(), ::toupper);
	return renterLastName;
}

//toUpper(command)