// By: Cristian Magana
// ID 37578770

#include "Renter.h"

Renter::Renter()
{
	this->renterFirstName = "";
	this->renterLastName = "";
	this->renterID = 1;
}

Renter::Renter(int rID, std::string rFirstName, std::string rLastName)
{
	if (rID < 1)
	{
		throw InvalidRenterIDException();
	}
	this->renterID = rID;
	this->renterFirstName = rFirstName;
	this->renterLastName = rLastName;

}

void Renter::setRenterID(int rID)
{
	this->renterID = rID;
}

int Renter::getRenterID()
{
	return renterID;
}

void Renter::setRenterFirstName(std::string rFirstName)
{
	this->renterFirstName = rFirstName;
}

std::string Renter::getRenterFirstName()
{
	return renterFirstName;
}

void Renter::setRenterLastName(std::string rLastName)
{
	this->renterLastName = rLastName;
}

std::string Renter::getRenterLastName()
{
	return renterLastName;
}



ostream& operator<<(ostream& os, Renter rentee)
{
	os << rentee.getRenterFirstName() << " " << rentee.getRenterLastName() << ", " << rentee.getRenterID() << std::endl;;

	return os;
}