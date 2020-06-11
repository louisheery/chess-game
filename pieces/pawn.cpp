// Author: Louis Heery

#include "pawn.h"

using namespace std;

Pawn::Pawn(bool isBlackInput, string pieceNameInput) : Piece(isBlackInput, pieceNameInput) {

}

bool Pawn::isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) {

    // Calculate horizontal and vertical distance of the current move
    int horizontalDistance = abs((int) (toPosition.at(0)) - (fromPosition.at(0)));
    int verticalDistance;

    // Vertical direction calculated based on which player is playing
    if (!isBlack) {
        verticalDistance = (int) (toPosition.at(1)) - (fromPosition.at(1));
    } else {
        verticalDistance = (int) (fromPosition.at(1)) - (toPosition.at(1));
    }

    // Check move is allowed for Pawn
    if (horizontalDistance == 0) {

        // Can only move 2 spaces forward if it is the Pawn's first move
        if (verticalDistance == 2) {
            if (board.at(fromPosition)->isFirstMove == false) {
                return false;
            }

            // Check there is no Piece obstructing the Pawn's path if moving 2 squares vertically
            string pathPosition;

            // Calculate position between from position and to position of pawn
            if (board.at(fromPosition)->isBlack) {
                pathPosition = string(1, toPosition.at(0)) + string(1, (char) (((int) toPosition.at(1) + 1)));
            } else {
                pathPosition = string(1, toPosition.at(0)) + string(1, (char) (((int) toPosition.at(1) - 1)));
            }

            // Returns false if piece found on the path
            try {
                board.at(pathPosition);
                return false;
            } catch (const std::out_of_range &error) {
            }

        }

        // Pawn must move forwards, and cannot move forwards more than 2 squares
        else if (verticalDistance < 1 || verticalDistance > 2) {
            return false;
        }

        // If To Position is occupied, pawn cannot go there because it is not capturing a piece
        try {
            board.at(toPosition);
            return false;
        } catch (const out_of_range &error) {

        }

        return true;
    }

    // If the Pawn is capturing another piece
    else if (horizontalDistance == 1 && verticalDistance == 1) {

        // Checks there is a piece at the Pawn's destination square
        try {
            board.at(toPosition);

            // Compared colour of Pawn to colour of Piece it is capturing
            if (board.at(toPosition)->isBlack == board.at(fromPosition)->isBlack) {
                return false; // Returns false if piece is same colour
            }
        } catch (const out_of_range &error) {
            return false; // Returns false if no piece found at destination
        }

        return true;
    }

    return false;
}

Pawn* Pawn::copyPiece() {
    // Return copy of Pawn object
    return new Pawn(this->isBlack, this->pieceName);
}

Pawn::~Pawn() {

}
