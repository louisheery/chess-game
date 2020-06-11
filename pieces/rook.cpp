// Author: Louis Heery

#include "rook.h"

using namespace std;

Rook::Rook(bool isBlackInput, string pieceNameInput) : Piece(isBlackInput, pieceNameInput) {

}

bool Rook::isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) {

    // Calculate horizontal and vertical distance of the current move
    int verticalDistance = (int) (toPosition.at(1)) - (fromPosition.at(1));
    int horizontalDistance = (int) (toPosition.at(0)) - (fromPosition.at(0));

    // Check move is allowed for Rook
    if (horizontalDistance == 0 && verticalDistance == 0) {
        return false;
    }

    // Check toPosition is not occupied by player's own piece
    try {
        board.at(toPosition);
        // CANT go on same colour piece
        if (board.at(toPosition)->isBlack == board.at(fromPosition)->isBlack) {
            return false;
        }
    } catch (const std::out_of_range &error) {
    }

    // Check Rook is travelling in a straight line
    if ((horizontalDistance != 0 && abs(verticalDistance) > 0) || (abs(horizontalDistance) > 0 && verticalDistance != 0)) {
        return false;
    }

    // Check no obstructions if Rook moving Vertically
    if (horizontalDistance == 0 && abs(verticalDistance) > 0) {

        // Find starting and End Row to Check
        char startRow = (char) min((char) fromPosition.at(1), (char) toPosition.at(1));
        char endRow = (char) max((char) fromPosition.at(1), (char) toPosition.at(1));

        string pieceLocationToCheck;

        // Loop through all squares on the Rooks route
        for (int i = 0; i < (endRow - startRow - 1); i++) {
            pieceLocationToCheck = string(1, ((char) fromPosition.at(0))) + string(1, ((char) startRow + i));
        }

        // Try completes if piece found at current Location
        try {
            board.at(pieceLocationToCheck);
            return false;

        } catch (const out_of_range &error) {
        }

        // Else returns true if no pieces along route
    }

    // Check no obstructions if Rook moving Horizontally
    if (abs(horizontalDistance) > 0 && verticalDistance == 0) {

        // Find starting and End Row to Check
        char startColumn = (char) min((char) fromPosition.at(0), (char) toPosition.at(0));
        char endColumn = (char) max((char) fromPosition.at(0), (char) toPosition.at(0));

        string pieceLocationToCheck;

        // Loop through all squares on the Rooks route
        for (int i = 0; i < (endColumn - startColumn - 1); i++) {
            pieceLocationToCheck = string(1, ((char) startColumn + i)) + string(1, fromPosition.at(1));
        }

        // Try completes if piece found at current Location
        try {
            board.at(pieceLocationToCheck);
            return false;

        } catch (const out_of_range &error) {
        }

        // Else returns true if no pieces along route
    }

    return true;

}

Rook* Rook::copyPiece() {
    // Return copy of Rook object
    return new Rook(this->isBlack, this->pieceName);
}

Rook::~Rook() {

}
