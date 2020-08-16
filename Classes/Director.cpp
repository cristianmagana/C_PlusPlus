/* 
	ICS45C: Summer 2020
	Cristian Magana 
	37578770

*/

#include "Director.h"
#include <iostream>

Director::Director()
{
	this->firstName = " ";
	this->lastName = " ";
	this->numOfProds = 0;
	this->yearOfBirth = 0;
}


void Director::setFirstName(std::string fname)
{
	this->firstName = fname;
}

std::string Director::getFirstName() //Gets the object that i am using, firstname; 
{ 
	return this->firstName;
}

void Director::setLastName(std::string lname)
{
	this->lastName = lname;
}

std::string Director::getLastName()
{
	return this->lastName;
}

void Director::setBirthYear(int byear)
{
	this->yearOfBirth = byear;
}

int Director::getBirthYear() 
{
	return this->yearOfBirth;
}

void Director::setNumOfMovies(int no_films)
{
	this->numOfProds = no_films;
}

int Director::getNumOfMovies() 
{
	return this->numOfProds;
}


Director::Director(std::string directorFirstname, std::string directorLastName, int directorYearOfBirth, int directorNumOfProd) {

	firstName = directorFirstname;
	lastName = directorLastName;
	yearOfBirth = directorYearOfBirth;
	numOfProds = directorNumOfProd; 
}

