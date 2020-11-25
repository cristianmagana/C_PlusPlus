/*

Jonathan Jin
SID# 17363386
UCINETID: jonathj

Cristian Magana
SID# 37578770
UCINETID: crmagan1

*/

#ifndef ___PROJECT_3_HPP
#define ___PROJECT_3_HPP

#include <string>
#include "Wordset.hpp"
using namespace std;

void loadWordsIntoTable(WordSet & words, std::istream & in);


std::string convert(std::string s1, std::string s2, const WordSet & words);



#endif
