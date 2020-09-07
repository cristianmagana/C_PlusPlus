// By: Cristian Magana
// ID 37578770


#ifndef MOVIES_H_
#define MOVIES_H_

#include "Renter.h"

class Movies {

private:
	std::string movieCode;
	std::string movieName;
	int numberOfRentedCopies;
	Renter Renters[10];

public:
	Movies();
	Movies(std::string mCode, std::string  mName);


	std::string getMovieCode();
	std::string getMovieName();
	int getRentedCopies();
	void rentMovie(Renter rentee);
	int getRentersID(int renteesID);
	void getRentersInfo();

	void returnRental(int rID);


	friend ostream& operator<<(ostream& os,  Movies movie);


};


#endif
