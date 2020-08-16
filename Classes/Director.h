#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include <iostream>
#include <string>

class Director {

private:
	std::string firstName;
	std::string lastName;
	int yearOfBirth;
	int numOfProds;

public: 
	Director();
	Director(std::string directorFirstname, std::string directorLastName, int directorYearOfBirth, int directorNumOfProd);
	void setFirstName(std::string fname);
	std::string getFirstName();
	void setLastName(std::string lname);
	std::string getLastName();
	void setBirthYear(int byear);
	int getBirthYear();
	void setNumOfMovies(int no_films);
	int getNumOfMovies();
	
};



#endif
