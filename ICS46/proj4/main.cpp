// Cristian Magana 
// 37578770
// crmagan1

// Jonathan Jin
// 17363386
// jonathj

#include <fstream>
#include <iostream>
#include <string>
#include "MyAVLTree.hpp"

using namespace std;

int main()
{
	//int k = 4;
	//int v = 111;
	//MyAVLTree<int, int> a;
	//a.insert(k, v);

	MyAVLTree<int, std::string> tree;

	//LEFT LEFT CASE
	tree.insert(20, "foo");
	tree.insert(15, "sna");
	tree.insert(10, "bar");
	tree.insert(17, "twelve");
	tree.insert(5, "7teen");
	tree.insert(12, "fifteen");
	tree.insert(25, "foo");
	tree.preOrder();










	// right
	//std::cout << "----------------inserting 5\n";
	//tree.insert(5, "foo");
	//std::cout << "----------------inserting 3\n";
	//tree.insert(3, "sna");
	//std::cout << "----------------inserting 10\n";
	//tree.insert(10, "bar");
	//std::cout << "----------------inserting 12\n";
	//tree.insert(12, "twelve");
	///*std::cout << "----------------inserting 9\n";
	//tree.insert(9, "7teen");*/
	//std::cout << "----------------inserting 11\n";
	//tree.insert(11, "fifteen");
	///*std::cout << "----------------inserting 17\n";
	//tree.insert(17, "7teen");*/


	// left 
	/*std::cout << "----------------Inserting 7\n";
	tree.insert(7, "foo");
	std::cout << "----------------Inserting 8\n";
	tree.insert(8, "sna");
	std::cout << "----------------Inserting 6\n";
	tree.insert(6, "bar");
	std::cout << "----------------Inserting 3\n";
	tree.insert(3, "twelve");
	std::cout << "----------------Inserting 9\n";
	tree.insert(9, "7teen");
	std::cout << "----------------Inserting 4\n";
	tree.insert(4, "fifteen");

	tree.preOrder();
	*/ 
	/*std::cout << "----------------Inserting 17\n";
	tree.insert(17, "7teen");*/
	


	/*std::cout << "----------------Inserting 30\n";
	tree.insert(30, "foo");
	std::cout << "----------------Inserting 20\n";
	tree.insert(20, "sna");
	std::cout << "----------------Inserting 40\n";
	tree.insert(40, "twelve");
	std::cout << "----------------Inserting 50\n";
	tree.insert(50, "bar");
	std::cout << "----------------Inserting 10\n";
	tree.insert(10, "fifteen");
	std::cout << "----------------Inserting 25\n";
	tree.insert(25, "fifteen");*/

	/*std::cout << "----------------Inserting 17\n";
	tree.insert(17, "7teen");
	std::cout << "----------------Inserting 9\n";
	tree.insert(9, "7teen");*/

	/*
	std::cout << "----------------Inserting 20\n";
	tree.insert(20, "twenty");

	std::cout << "----------------Inserting 25\n";
	tree.insert(25, "25");
	std::cout << "----------------Inserting 9\n";
	tree.insert(9, "9");
	std::cout << "----------------Inserting 8\n";
	tree.insert(8, "8");
	std::cout << "----------------Inserting 7\n";
	tree.insert(7, "7");
	std::cout << "------------------------------\n";
	cout << "contains: " << tree.contains(15) << endl;
	cout << "size: " << tree.size() << endl;
	//cout << "find: " << tree.find(10) << endl;
	//cout << "find: " << tree.find(5) << endl;
	//cout << "find: " << tree.find(15) << endl;
	//cout << "find: " << tree.find(1) << endl;
*/	
    return 0;
}

