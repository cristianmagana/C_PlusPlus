// By: Cristian Magana
// ID 37578770


#ifndef RENTER_H_
#define RENTER_H_

#include "Exceptions.cpp"

class Renter {

private:
	int renterID;
	std::string renterFirstName;
	std::string renterLastName;

public:
	Renter();
	Renter(int rID, std::string rFirstName, std::string rLastName);
	void setRenterID(int rID);
	int getRenterID();
	void setRenterFirstName(std::string rFirstName);
	std::string getRenterFirstName();
	void setRenterLastName(std::string rLastName);
	std::string getRenterLastName();

	friend ostream& operator<<(ostream& os, Renter rentee);
};

#endif
