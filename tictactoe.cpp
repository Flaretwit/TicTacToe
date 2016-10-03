/* TicTacToe */
//In this game, the loser from the previous game goes first. Outputs the number of wins O has compared to X.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

#define TIE = 1;
#define OPLAYER = 2;
#define XPLAYER = 3;
using namespace std;
struct Move;
bool checkTie(char(*gameboard)[3]);
bool checkWin(char player, char(*gameboard)[3]);
void printBoard(char(*gameboard)[3]);

//a better main function

int main() {
	int owins, xins, turncount;
	const BLANK = 1;
	const OMOVE = 2;
	const XMOVE = 3;
	Move m;
	//while loop for multple games
	
	
	do {
	
	int gameboard[3][3];
	int** gameboard = gameboard;
	//sets the gameboard
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			gameboard = BLANK;
		}

	}

	while(!checkWin(&gameboard, &m) || turncount == 9) {
		
		turncount++;
	}

	char choice[2];
	
	cout << "O wins: " + owins;
	cout << "X wins: " + xwins;
	cout << "Do you wish to keep playing? (y/n)";
	
	cin.getLine(choice, 1);

	}while(keepplaying);


}


//from Vikram Kashyap's wonderful and intelligent code
struct Move(int x, int y, int player) {

}

//checks for a win by checking all the columns, rows and diagonals for a player
//returns a boolean 
int checkWin(Move *m, int(*gameboard)[3])i {
	int counter[4] = 0;
	for(int i = 0; i < 3; i++) {
		//checks for the vertical column
		if(gameboard[m->x][i] == m->player) counter[0]++;
		//checks for the horizonal row
		if(gameboard[i][m->] == m->player) counter[1]++;
		//checks for topleft to bottomright diagonal
		if(gameboard[i][i] == m->player) counter[2]++;
		//checks for bottomleft to topright diagonal
		if(gameboard[i][2-i] == m->player) counter[3]++;
	}
	for(int j = 0; j < 4; j++) {
		if(counter[j] == 3) return player;
	}
	return TIE;
}

void printBoard(int(*gameboard)[3]) {
	cout << "\t a\t b\t c\n";
	for(int i = 0; i < 3; i++) {
		cout << i + 1 << "\t"; 
		for(int j = 0; j < 3; j++) {
			cout << gameboard[i][j] << "\t";
		}
		cout << "\n";

	}
}
