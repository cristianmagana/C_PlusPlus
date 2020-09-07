#include <iostream>

using namespace std;

void passByValue(int x);
void passByReference(int *x);

int main() {
	
	//************* Memory Location and Pointers**************************
	int fish = 5;
	// "&" is address operator &fish address of variable. 
	cout << &fish << endl;
	
	
	//Pointer - special type of variable that points to a memory address. Contain memory address as a value. 
	int *fishPointer;
	fishPointer  = &fish; 
	cout << fishPointer << endl;
	
	//**************** Pass by refernce with Pointers*********************
	// Pass by value -- Passing a copy of a value to a function
	
	// Pass by refernce -- Passing the memory address to a function giving it direct access to change the orginial value.. 
		int Cristian = 27;
		
		int Carlos = 27; 
	
		passByValue(Cristian);
		passByReference(&Carlos); 
		
		cout << "Cristian is now " << Cristian << endl;
		cout << "Carlos is now " << Carlos << endl;
	
	
}

void passByValue(int x) {
	x = 99;
}

void passByReference(int *x) {
	*x=66;
}
