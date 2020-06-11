// Author: Louis Heery

#include "bishop.h"

using namespace std;

Bishop::Bishop(bool isBlackInput, string pieceNameInput) : Piece(isBlackInput, pieceNameInput) {

}

bool Bishop::isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) {

    // Calculate horizontal and vertical distance of the current move
    int verticalDistance = (int) (toPosition.at(1)) - (fromPosition.at(1));
    int horizontalDistance = (int) (toPosition.at(0)) - (fromPosition.at(0));

    // Check move is allowed for Bishop
    if (horizontalDistance == 0 && verticalDistance == 0) {
        return false;
    }

    if (abs(horizontalDistance) != abs(verticalDistance)) {
        return false;
    }

    // Check toPosition is not occupied by player's own piece
    try {
        board.at(toPosition);
        if (board.at(toPosition)->isBlack == board.at(fromPosition)->isBlack) {
            return false;
        }
    } catch (const out_of_range &error) {
    }

    // Check for Diagonal Obstructions //
    // 1. Calculate start and end column and row
    char startColumn = (char) min((char) fromPosition.at(0), (char) toPosition.at(0));
    char endColumn = (char) max((char) fromPosition.at(0), (char) toPosition.at(0));
    char startRow = (char) min((char) fromPosition.at(1), (char) toPosition.at(1));
    char endRow = (char) max((char) fromPosition.at(1), (char) toPosition.at(1));

    // 2. Determine if diagonal is positive or negative
    bool positiveDiagonal = ((toPosition.at(0) - fromPosition.at(0)) == (toPosition.at(1) - fromPosition.at(1)));

    // 3. Loop through each position to be checked in diagonal
    string pieceLocationToCheck;
    for (int i = 1; i < (endColumn - startColumn); i++) {

        if (positiveDiagonal) {
            pieceLocationToCheck = string(1, ((char) startColumn + i)) + string(1, ((char) startRow + i));
        } else {
            pieceLocationToCheck = string(1, ((char) startColumn + i)) + string(1, ((char) endRow - i));
        }

        // False returned unless no piece found at all locations along diagonal path
        try {
            board.at(pieceLocationToCheck);
            return false;

        } catch (const out_of_range &error) {
        }
    }

    // True returned if all locations along diagonal are empty
    return true;
}

Bishop* Bishop::copyPiece() {
    // Return copy of Bishop object
    return new Bishop(this->isBlack, this->pieceName);
}


Bishop::~Bishop() {

}
