#include <iostream>


using namespace std; 

int main() {
	
	int lotteryArray[] = {1, 11, 22, 33, 44, 55, 66, 77, 88, 99};
	int userInput = -1;
	int index = -1;
	char endGame = ' ';
	bool hasWon = false;
	
	while(true) {
		cout << "Feeling lucky punk?\n"
			 << "Enter a number to play the lottery" << endl;
			 
		cin >> userInput;
		
		for(index =0; index < 10; index++) {
			if(userInput ==lotteryArray[index]) {
				hasWon=true;
				cout << "Congrats you won, nothing!\n"
				     << "The number was found at index " << index << endl;
				break;
			}
	}
	
	if (!hasWon) cout << "Sorry, you guessed wrong loser" << endl;
	cout << "Wanna play again? y or n" << endl;
	cin >> endGame;
	if (endGame == 'n') break;
	
}
	return 0;
}
