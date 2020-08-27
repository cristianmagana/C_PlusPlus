#include "Director.h"


Director::Director()
{
	this->firstName = " ";
	this->lastName = " ";
	this->numOfProds = 0;
	this->yearOfBirth = 0;
}


void Director::setFirstName(std::string FirstName)
{
	this->firstName = FirstName;
}

std::string Director::getFirstName() //Gets the object that i am using, firstname; 
{ 
	return this->firstName;
}

void Director::setLastName(std::string LastName)
{
	this->lastName = LastName;
}

std::string Director::getLastName()
{
	return this->lastName;
}

void Director::setBirthYear(int YearOfBirth)
{
	this->yearOfBirth = YearOfBirth;
}

int Director::getBirthYear() 
{
	return this->yearOfBirth;
}

void Director::setNumOfMovies(int NumberOfFilms)
{
	this->numOfProds = NumberOfFilms;
}

int Director::getNumOfMovies() 
{
	return this->numOfProds;
}


Director::Director(std::string FirstName, std::string LastName, int YearOfBirth, int NumberOfFilms) {

	firstName = FirstName;
	lastName = LastName;
	yearOfBirth = YearOfBirth;
	numOfProds = NumberOfFilms;
}

