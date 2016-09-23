/* TicTacToe */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


bool checkWin(char player, char(*gameboard)[3]);
void printBoard(char(*gameboard)[3]);
int main() {
	char gameboardthing[3][3];
	char (*gameboard)[3] = gameboardthing;
	char move[3];
	char whoseturn = 'X';
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			gameboard[i][j] = ' ';	
		}
	}
	do {
	cout << "Make your move " << whoseturn << "\n";
	cin.getline(move, sizeof(move));
	cout << move[0] << move[1];
	int row = move[0] - 49;
	int column = move[1] - 97;
	cout << row;
	cout << column;
	gameboard[column][row] = whoseturn;

	if(whoseturn == 'X') {
		whoseturn = 'O';
	} else {
		whoseturn = 'X';
	}
	printBoard(gameboard);


	} while(checkWin(whoseturn, gameboard) == false);
	return 0;	
}


bool checkWin(char player, char(*gameboard)[3]) {
	bool playerWon = false;
	if(gameboard[0][0] == player &&
		gameboard[1][0] == player &&
		gameboard[2][0] == player) {
		playerWon = true;
	}
	if(gameboard[0][1] == player &&
		gameboard[1][1] == player &&
		gameboard[2][1] == player) {
		playerWon = true;
	}
	if(gameboard[0][2] == player &&
		gameboard[1][2] == player &&
		gameboard[2][2] == player) {
		playerWon = true;
	}
	if(gameboard[0][0] == player &&
		gameboard[0][1] == player &&
		gameboard[0][2] == player) {
		playerWon = true;
	}
	if(gameboard[1][0] == player &&
		gameboard[1][1] == player &&
		gameboard[1][2] == player) {
		playerWon = true;
	}
	if(gameboard[2][0] == player &&
		gameboard[2][1] == player &&
		gameboard[2][2] == player) {
		playerWon = true;
	}
	if(gameboard[0][0] == player &&
		gameboard[1][1] == player &&
		gameboard[2][2] == player) {
		playerWon = true;
	}	
	if(gameboard[2][0] == player &&
		gameboard[1][1] == player &&
		gameboard[0][2] == player) {
		playerWon = true;
	}

	return playerWon;
}

void printBoard(char(*gameboard)[3]) {
		
	cout << "\ta\tb\tc\n";
	cout << "1\t" << gameboard[0][0] << "\t" << gameboard[1][0] << "\t" << gameboard[2][0] << "\n";	
	cout << "2\t" << gameboard[0][1] << "\t" << gameboard[1][1] << "\t" << gameboard[2][1] << "\n";	
	cout << "3\t" << gameboard[0][2] << "\t" << gameboard[1][2] << "\t" << gameboard[2][2] << "\n";
}
