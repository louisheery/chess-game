// Author: Louis Heery

#include "queen.h"

using namespace std;

Queen::Queen(bool isBlackInput, string pieceNameInput) : Piece(isBlackInput, pieceNameInput) {

}

bool Queen::isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) {

    // Calculate horizontal and vertical distance of the current move
    int verticalDistance = (int) (toPosition.at(1)) - (fromPosition.at(1));
    int horizontalDistance = (int) (toPosition.at(0)) - (fromPosition.at(0));

    // Check move is allowed for Queen
    if (horizontalDistance == 0 && verticalDistance == 0) {
        return false;
    }

    if ((abs(horizontalDistance) > 0 && abs(verticalDistance) > 0) && (abs(horizontalDistance) != abs(verticalDistance)))
    {
        return false;
    }

    // Check toPosition is not occupied by player's own piece
    try
    {
        board.at(toPosition);
        if (board.at(toPosition)->isBlack == board.at(fromPosition)->isBlack)
        {
            return false;
        }
    }
    catch (const std::out_of_range &error)
    {
    }

    if ((abs(horizontalDistance == 1) || horizontalDistance == 0) && (abs(verticalDistance == 1) || verticalDistance == 0)) {
        return true;
    }

    // Check no obstructions if Queen moving Diagonally
    if (abs(horizontalDistance) > 0 && abs(verticalDistance) > 0) {

        // Check no obstructions if Queen moving Diagonally
        // 1. Calculate start and end column and row
        char startColumn = (char)min((char)fromPosition.at(0), (char)toPosition.at(0));
        char endColumn = (char)max((char)fromPosition.at(0), (char)toPosition.at(0));
        char startRow = (char)min((char)fromPosition.at(1), (char)toPosition.at(1));
        char endRow = (char)max((char)fromPosition.at(1), (char)toPosition.at(1));

        // 2. Determine if diagonal is positive or negative
        bool positiveDiagonal = ((toPosition.at(0) - fromPosition.at(0)) == (toPosition.at(1) - fromPosition.at(1)));

        // 3. Loop through each position to be checked in diagonal
        string pieceLocationToCheck;
        for (int i = 1; i < (endColumn - startColumn); i++)
        {

            // Piece Location to check is based on whether diagonal path is positive or negative
            if (positiveDiagonal)
            {
                pieceLocationToCheck = string(1, ((char)startColumn + i)) + string(1, ((char)startRow + i));
            }
            else
            {
                pieceLocationToCheck = string(1, ((char)startColumn + i)) + string(1, ((char)endRow - i));
            }

            // False returned unless no piece found at all locations along diagonal path
            try
            {
                board.at(pieceLocationToCheck);
                return false;
            }
            catch (const out_of_range &error)
            {
            }

        }
    }

    // Check no obstructions if Queen moving Vertically
    else if (horizontalDistance == 0 && abs(verticalDistance) > 0) {

        // Find starting and End Row to Check
        char startRow = (char) min((char) fromPosition.at(1), (char) toPosition.at(1));
        char endRow = (char) max((char) fromPosition.at(1), (char) toPosition.at(1));

        string pieceLocationToCheck;

        // Loop through all squares on the Queens route
        for (int i = 0; i < (endRow - startRow); i++) {
            pieceLocationToCheck = string(1, ((char) fromPosition.at(0))) + string(1, ((char) startRow + i));
        }

        // Try completes if piece found at current Location
        try {
            board.at(pieceLocationToCheck);
            return false;

        } catch (const out_of_range &error) {
        }
    }

    // Check no obstructions if Queen moving Horizontally
    else if (abs(horizontalDistance) > 0 && verticalDistance == 0) {

        // Find starting and End Row to Check
        char startColumn = (char) min((char) fromPosition.at(0), (char) toPosition.at(0));
        char endColumn = (char) max((char) fromPosition.at(0), (char) toPosition.at(0));

        string pieceLocationToCheck;

        // Loop through all squares on the Queens route
        for (int i = 0; i < (endColumn - startColumn); i++) {
            pieceLocationToCheck = string(1, ((char) startColumn + i)) + string(1, fromPosition.at(1));
        }

        // Try completes if piece found at current Location
        try {
            board.at(pieceLocationToCheck);
            return false;

        } catch (const out_of_range &error) {
        }
    }

    return true;

}

Queen* Queen::copyPiece() {
    // Return copy of Queen object
    return new Queen(this->isBlack, this->pieceName);
}

Queen::~Queen() {

}
