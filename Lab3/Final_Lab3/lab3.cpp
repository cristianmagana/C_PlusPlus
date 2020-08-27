// By: Cristian Magana
// ID 37578770

#include "MovieManager.h"

int main()
{
		std::cout << "Welcome to Movie Rental Kiosk!" << std::endl;

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
			catch (EmptyMovieListException& e) {
				std::cerr << "Thrown when trying to discontinue a movie when the inventory list is empty." << std::endl;
			}
			catch (EmptyRenterListException& e) {
				std::cerr << "Thrown when trying to return a movie that does not have any copies currently being rented." << std::endl;
			}
			catch (RenterLimitException& e) {
				std::cerr << "Thrown when a renter is renting to a movie without any available copies." << std::endl;
			}
			catch (DuplicateRenterException& e) {
				std::cerr << "Thrown when trying to remove a renter for a movie that doesn’t exist." << std::endl;
			}
			catch (RenterNotFoundException& e) {
				std::cerr << "Thrown when trying to add a renter to a movie and a duplicate renter ID exists" << std::endl;
			}
			catch (InvalidRenterIDException& e) {
				std::cerr << "Thrown when the user enters an invalid renter ID." << std::endl;
			}
			catch (EmptyRenterNameException& e) {
				std::cerr << "Thrown when the user enters an empty first and/or last name for the renter." << std::endl;
			}
			catch (RentedMovieException& e) {
				std::cerr << "Thrown when the user attempts to discontinue a movie that has copies currently rented out." <<std::endl;
			}
		}
	return 0;
}
