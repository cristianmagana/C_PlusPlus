//
// Creates an exception class. 
//
// General rule is that exceptions are safe guards from bad things happening.
// These are thrown near boundaries (i.e.; before segmenation fault occurs). 
// Once the object is thrown, you create an object (of type E) locally. 
// 		The processes of throwing copies this object to some private memory location not defined by the standard. 
//	When you catch the object:
// 		You are getting a reference to the object at the private location it was copied to. 
//      Its not a const (or temporary) value so you can have a normal reference to it.
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

///////////////////////THROW AN EXEXPTION///////////////////////
if (numberOfAvailableMovies == 0)
			{
				throw EmptyMovieListException();
				return;
			}
			
//////////////////////////////////////////////////////////////////
///////////////////CATCH ESLEWHERE IN THE PROGRAM///////////////////////
//////////////////////////////////////////////////////////////////

		bool run = true;
		MovieManager runningProgram;

		while (run == true)
		{
			try {
				runningProgram.run();

			}
			catch (DuplicateMovieException& e){
				std::cerr << "Thrown when a movie already exists when trying to add a new movie." << std::endl;
			}
			catch (MovieLimitException& e) {
				std::cerr << "Thrown when a movie is trying to be added and the number of movies is at the at the max (I.e. 20)." << std::endl;
				}
			catch (EmptyMovieInfoException& e) {
				std::cerr << "Thrown when the movie code and /or movie name is empty when trying to add one to the movie array." << std::endl;
			}
			catch (MovieNotFoundException& e) {
				std::cerr << "Thrown when trying to do something with movie that does not exist." << std::endl;
			}
		}