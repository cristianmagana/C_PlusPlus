#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include <iostream>
#include <string>
using namespace std;

class Director {

private:
	string firstName;
	string lastName;
	int yearOfBirth;
	int numOfProds;

public: 
	Director();
	Director(string directorFirstname, string directorLastName, int directorYearOfBirth, int directorNumOfProd);
	void setFirstName(string fname);
	string getFirstName();
	void setLastName(string lname);
	string getLastName();
	void setBirthYear(int byear);
	int getBirthYear();
	void setNumOfMovies(int no_films);
	int getNumOfMovies();
	
};



#endif
