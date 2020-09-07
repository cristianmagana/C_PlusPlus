#include <iostream>
#include <string>

using namespace std;

int moves(0);
void hanoi(int n, string start, string aux, string end) {
	moves++; 
		if (n == 1) //hanoi(1, start, aux, end)
		cout << "move disc " << start << " to " << end << endl; //move the bottom 1 to destination location
	else
	{
		hanoi(n - 1, start, end, aux); //move top disk to aux
		cout << "move disc " << start << " to " << end << endl;
		hanoi(n - 1, aux, start, end); //move the total n-1 discs to aux
		
	}
}

int main() {
	string a = "A", b = "B", c = "C";
	int n;
	cout << "Please enter how many discs to start: ";
	cin >> n;
	cout << "Sorting discs. . . " << endl;
	hanoi(n, a, b, c);
	cout << "Total of " << moves << " movements." << endl;

	system("PAUSE");
	return 0;
}

