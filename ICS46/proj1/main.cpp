// If you really want to make a program for the app, be my guest.
// You may prefer to do so in /exp instead.
// Or better yet, use gtest to automate your own test cases!
#include <iostream>
#include <string>
#include <limits>
#include <map>
#include "proj1.hpp"


int main()
{
    bool RUN = true; 

    while (RUN)
    {
        std::string s1_input = "";
        std::getline(std::cin, s1_input);

        std::string s2_input = "";
        std::getline(std::cin, s2_input);

        std::string s3_input = "";
        std::getline(std::cin, s3_input);

        std::map<char, unsigned> mappingBlank; 

        bool checkSolution = puzzleSolver(s1_input, s2_input, s3_input, mappingBlank);
        std::cout << "The Mapping Was: " << checkSolution << std::endl;

        for (const auto& x : mappingBlank) 
        {
            std::cout << x.first << ": " << x.second << "\n";
        }

        char response = 'y';
        std::cout << "Continue? y/n" << std::endl;
        std::cin >> response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if(response != 'y')
        {
            RUN = false; 
        }
    }

    return 0;
}



