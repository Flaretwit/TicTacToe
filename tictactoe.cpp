/* TicTacToe */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int gameboard[3][3];
	char whoseturn = 'X';
	return 0;
	

	do {
		cout << "TicTacToe on C++\n"
		cout << "\ta\tb\tc"
		cout << "1\t" << gameboard[0][0] << "\t" << gameboard[1][0] << "\t" << gameboard[2][0]	
	}
	while(checkWin(whoseturn, gameboard) == false); 
}

bool checkWin(char player, int gameboard[3][3]) {
	bool playerWon = false
	if(gameboard[0][0] == player &&
		gameboard[1][0] == player
		gameboard[2][0] == player) {
		playerWon = true;
	}
	if(gameboard[0][1] == player &&
		gameboard[1][1] == player
		gameboard[2][1] == player) {
		playerWon = true;
	}
	if(gameboard[0][2] == player &&
		gameboard[1][2] == player
		gameboard[2][2] == player) {
		playerWon = true;
	}
	if(gameboard[0][0] == player &&
		gameboard[0][1] == player
		gameboard[0][2] == player) {
		playerWon = true;
	}
	if(gameboard[1][0] == player &&
		gameboard[1][1] == player
		gameboard[1][2] == player) {
		playerWon = true;
	}
	if(gameboard[2][0] == player &&
		gameboard[2][1] == player
		gameboard[2][2] == player) {
		playerWon = true;
	}
	if(gameboard[0][0] == player &&
		gameboard[1][1] == player
		gameboard[2][2] == player) {
		playerWon = true;
	}	
	if(gameboard[2][0] == player &&
		gameboard[1][1] == player
		gameboard[0][2] == player) {
		playerWon = true;
	}

	return playerWon;
}

