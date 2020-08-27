/* 
	ICS45C: Summer 2020
	Cristian Magana 
	37578770

*/

#include "Director.h"
#include <iostream>


void Director::setFirstName(string fname)
{
	this->firstName = fname;
}

string Director::getFirstName() //Gets the object that i am using, firstname; 
{ 
	return this->firstName;
}

void Director::setLastName(string lname)
{
	this->lastName = lname;
}

string Director::getLastName() 
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











Director::Director(string directorFirstname, string directorLastName, int directorYearOfBirth, int directorNumOfProd) {

	firstName = directorFirstname;
	lastName = directorLastName;
	yearOfBirth = directorYearOfBirth;
	numOfProds = directorNumOfProd; 
}

