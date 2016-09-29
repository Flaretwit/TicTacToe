/* TicTacToe */
//In this game, the loser from the previous game goes first. Outputs the number of wins O has compared to X.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;
bool checkTie(char(*gameboard)[3]);
bool checkWin(char player, char(*gameboard)[3]);
void printBoard(char(*gameboard)[3]);
int main() {
	int owins;
	int xwins;
	char whowon = ' ';
	char whoseturn = 'O';
	bool keepplaying = true;
	char decision[2];
	do{
		//defines the array and its pointer
		char gameboardthing[3][3];
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				gameboardthing[i][j] = ' ';
			}
		}
		int turncount = 0;
		char (*gameboard)[3] = gameboardthing;
		char move[3];
		//while loop manages the entire game
		//Since the while loop only goes on if there is a value of 1,
		//the arguments in the parentheses must return 0.
		//The or statement guarantees that both must be zero in order for the
		//two arguments together to return 0.
			while(!(checkWin(whoseturn, gameboard) || turncount == 9)) {
			//checks for a win
			printBoard(gameboard);
			cout << "Make your move " << whoseturn << "\n";
			//gets input
			cin.getline(move, sizeof(move));
			int row = move[0] - 49;
			int column = move[1] - 97;

			//checks if the chosen square is already occupied
			if(gameboard[column][row] == ' ') {
			//sets that element in the array to whose turn it is
				if(turncount % 2 == 0) {
					whoseturn = 'X';
				}
				if(turncount % 2 == 1) {
					whoseturn = 'O';
				}
				gameboard[column][row] = whoseturn;
			} else {
				cout << "That space is already filled! \n";
				turncount--;	
			}
			//alternates the variable to change whose turn
			turncount++;
			
			}
		//based on whose turn it was when the game ended
		if(checkTie(gameboard)) {
			cout << "Tie!";
		}
		else {
			if(whoseturn == 'X') {
				xwins++;
				whoseturn = 'O';
				cout << "X wins!\n";
				cout << "X has: " << xwins << "\n";	
			} else if(whoseturn == 'O') {
				owins++;
				whoseturn = 'X';
				cout << "O wins!\n";
				cout << "O has: " << owins << "\n";
			}
		}
		
		cout << "Do you want to continue playing? (y/n)";
		cin >> decision;
		if(!strcmp(decision, "n")) {
			keepplaying = false;		
		}

		
	}while(keepplaying);
	
	return 0;	
}

bool checkTie(char(*gameboard)[3]) {
	if(!checkWin('X', gameboard) && !checkWin('O', gameboard)) {
		return true;
	}
	return false;
}
//checks for a win by checking all the columns, rows and diagonals for a player
//returns a boolean 
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
