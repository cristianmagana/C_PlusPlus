#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include <iostream>
#include <string>
using namespace std;

class Director {

private:
	std::string firstName;
	std::string lastName;
	int yearOfBirth;
	int numOfProds;

public: 
	Director();
	Director(std::string FirstName, std::string LastName, int YearOfBirth, int NumberOfFilms);
	void setFirstName(std::string FirstName);
	std::string getFirstName();
	void setLastName(std::string LastName);
	std::string getLastName();
	void setBirthYear(int YearOfBirth);
	int getBirthYear();
	void setNumOfMovies(int NumberOfFilms);
	int getNumOfMovies();
	
};



#endif
