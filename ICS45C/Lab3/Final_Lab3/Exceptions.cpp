// By: Cristian Magana
// ID 37578770

#include <exception>
#include <string>
#include <iostream>
using namespace std;


	
class DuplicateMovieException :public std::exception {};
class MovieLimitException :public std::exception {};
class EmptyMovieInfoException :public std::exception {};
class MovieNotFoundException :public std::exception {};
class EmptyMovieListException :public std::exception {};
class EmptyRenterListException :public std::exception {};
class RenterLimitException :public std::exception {};
class DuplicateRenterException :public std::exception {};
class RenterNotFoundException :public std::exception {};
class InvalidRenterIDException :public std::exception {};
class EmptyRenterNameException :public std::exception {};
class RentedMovieException :public std::exception {};

