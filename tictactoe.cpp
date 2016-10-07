/* TicTacToe */
//In this game, the loser from the previous game goes first. Outputs the number of wins O has compared to X.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Move {
	int x;
	int y;
	int player;
};


int checkWin(Move *m, int(*gameboard)[3]);
void printBoard(int(*gameboard)[3]);
Move getMove(char *input, int player);
char* getInput();
//a better main function

int main() {

	char* move;
	int owins = 0;
	int xwins = 0;
	int turncount = 0;
	bool keepplaying = true;
	const int BLANK = 1;
	struct Move m;
	m.x = 0;
	m.y = 0;
	m.player = 0;

	//while loop for multple games
	
	
	do {
	cout << "TicTacToe on C!"
	int gameboardthing[3][3];
	int(*gameboard)[3] = gameboardthing;
	//sets the gameboard
	for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				gameboard[i][j] = BLANK;
		}
	}
	//while no one has won or while the turncount isn't 9, runs game
	while(!checkWin(&m, gameboard) || turncount == 9) {
		move = getInput();
		m = getMove(move, turncount % 2);
		gameboard[m.x][m.y] = m.player;
		printBoard(gameboard);
		turncount++;
	}
		const int TIE = 1;
		const int OWIN = 2;
		const int XWIN = 3;
	//another helpful idea from Vikram.
	//if the turncount is 9, the expression becomes equal to one
	//which is also the value of tie, so it goes to tie in that case
	switch(checkWin(&m, gameboard)) {	
		case TIE:
			if(turncount == 9) cout << "Tie!";
			break;
		case OWIN:
			cout << "O wins!";
			owins++;
			break;
		case XWIN:
			cout << "X wins!";
			xwins++;
			break;
	}
		

	char *choice;
	
	cout << "O wins: " + owins;
	cout << "X wins: " + xwins;
	cout << "Do you wish to keep playing? (y/n)";
	
	choice = getInput();
	if(!strcmp(choice, "n")) keepplaying = false;
	}while(keepplaying);


}



//checks for a win by c:w
//hecking all the columns, rows and diagonals for a player
//returns a 2 for OWIN, 3 for XWIN and 0 for indeterminate
//the switch statement above then checks if the indeterminate result is a tie
int checkWin(Move *m, int(*gameboard)[3]) {
	int counter[4];
	for(int i = 0; i < 3; i++) {
		counter[i] = 0;
		//checks for the vertical column
		if(gameboard[m->x][i] == m->player) counter[0]++;
		//checks for the horizonal row
		if(gameboard[i][m->y] == m->player) counter[1]++;
		//checks for topleft to bottomright diagonal
		if(gameboard[i][i] == m->player) counter[2]++;
		//checks for bottomleft to topright diagonal
		if(gameboard[i][2-i] == m->player) counter[3]++;
	}
	for(int j = 0; j < 4; j++) {
		if(counter[j] == 3) return m->player;
	}
	return 0;
}
//prints the board
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
Move getMove(char *input, int player) {	
	char output[3];

	while(1) {
		cin.getline(output, sizeof(output));
		if(output[0] < 1 || output[0] > 3 || output[1] > 99 || output[1] < 97) {
			cout << "Invalid input";
			cin.clear();
			cin.ignore(1000. '\n');
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
char* getInput() {
	char *input = new char[2];
	bool valid = false;

	while(!valid) {
		valid = true;
		cin >> input;
	       if(cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter in the format of column, row (1a).";
			valid = false;			
	       }	       
	}

	return input;
}




