// Author: Louis Heery

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

#include "ChessBoard.h"

using namespace std;


void startExampleGame(ChessBoard& cb) {

	// Instantiate a new ChessBoard object

	cb.resetBoard();
	cb.printBoard();

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("B4", "C3");
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';

	cb.submitMove("D3", "G6");
	cout << '\n';

}

void startNewGame(ChessBoard& cb) {
	// Instantiate a new ChessBoard object

	cb.resetBoard();
	cb.printBoard();

	while (!cb.getHasGameEnded()) {

		cout << "\n" << (cb.getIsWhiteTurn() ? "White's" : "Black's");
		cout << " turn to go:" << endl;

		string startPos = "";
		string endPos = "";

		cout << "Enter Source Position: ";

		getline(cin >> ws, startPos);

		cout << "Enter Destination Position: ";
		getline(cin >> ws, endPos);


		cb.submitMove(startPos, endPos);
		cout << '\n';

	}
}

void startEngineTesting(ChessBoard& cb) {

	cb.resetBoard();

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';

}


int main() {

	cout << "========================\n";
	cout << " Welcome to Chess Game \n";
	cout << "========================\n\n";

	ChessBoard cb;

	char userInput = '\0';

	while (userInput != 't') {
		cout << "-- Select an Option --\n\n";

		cout << "a = Start New Game\n";
		cout << "b = Run Example Game\n";
		cout << "c = Test the Game Engine\n";
		cout << "d = Terminate Program\n\n";

		cin >> userInput;

		switch(userInput) {
			case 'a':
				startNewGame(cb);
				break;

			case 'b':
				startExampleGame(cb);
				break;

			case 'c':
				startEngineTesting(cb);
				break;

			case 'd':
				return 0;
		}
	}

	return 0;
}
