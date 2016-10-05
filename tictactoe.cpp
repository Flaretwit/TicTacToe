/* TicTacToe */
//In this game, the loser from the previous game goes first. Outputs the number of wins O has compared to X.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

#define TIE = 1;
#define OWIN = 2;
#define XWIN = 3;
using namespace std;
struct Move;
bool checkTie(char(*gameboard)[3]);
bool checkWin(char player, char(*gameboard)[3]);
void printBoard(char(*gameboard)[3]);
Move getMove(char input[3], int player);
char[] getInput();
//a better main function

int main() {
	char move[3];
	int owins, xins, turncount;
	bool keepplaying = true;
	const int BLANK = 1;
	const int OMOVE = 2;
	const int XMOVE = 3;
	Move m;
	//while loop for multple games
	
	
	do {
	:
	int gameboard[3][3];
	int** gameboard = gameboard;
	//sets the gameboard
	for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
			gameboard = BLANK;
		}
	}
	//while no one has won or while the turncount isn't 9, runs game
	while(!checkWin(&m, &gameboard) || turncount == 9) {
		move = getInput();
		m = getMove(move, turncount % 2);
		gameboard[m.x][m.y] = m.player;
		printBoard(&gameboard);
		turncount++;
	}
	//another helpful idea from Vikram.
	//if the turncount is 9, the expression becomes equal to one
	//which is also the value of tie, so it goes to tie in that case
	switch(checkWin(&m, &gameboard) || turncount == 9) {
		case TIE:
			cout << "Tie!";
		case OWIN:
			cout << "O wins!";
			owins++;
		case XWIN:
			cout << "X wins!";
			xwins++;
	}
		

	char choice[2];
	
	cout << "O wins: " + owins;
	cout << "X wins: " + xwins;
	cout << "Do you wish to keep playing? (y/n)";
	
	choice = getInput();
	if(!strcmp(choice, "n")) keepplaying = false;
	}while(keepplaying);
c++

}


//from Vikram Kashyap's wonderful and intelligent code
struct Move(int x, int y, int player) {

}

//checks for a win by c:w
//hecking all the columns, rows and diagonals for a player
//returns a boolean 
int checkWin(Move *m, &gameboard) {
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
//given a character array, returns a Move object.
Move getMove(char input[3], int player) {	
	char output[3];
	cin.getLine(output, sizeof(output);
	while(1) {
		if(output[0] < 1 || output[0] > 3 || output[1] > 99 || output[1] < 97) {
			cout << "Invalid input";
		} else {
			break;
		}
	}
	
	Move m;
	m.x= input[0] - 49;
	m.y = input[1] - 97;
	m.player = player;
	return m;
}
//gets input
char[] getInput() {
	char input[2];
	bool valid = false;

	while(!valid) {
		valid = true;
		cin >> input;
	       if(cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Please enter in the format of column, row (1a).";
			valid = false;			
	       }	       
	}

	return input;
}




