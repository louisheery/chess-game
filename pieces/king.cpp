// Author: Louis Heery

#include "king.h"

using namespace std;

King::King(bool isBlackInput, string pieceNameInput) : Piece(isBlackInput, pieceNameInput) {

}

bool King::isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) {

    // Calculate horizontal and vertical distance of the current move
    int verticalDistance = (int) (toPosition.at(1)) - (fromPosition.at(1));
    int horizontalDistance = (int) (toPosition.at(0)) - (fromPosition.at(0));

    // Check move is allowed for King
    if (horizontalDistance == 0 && verticalDistance == 0) {
        return false;
    }

    if (horizontalDistance > 1 || horizontalDistance < -1 || verticalDistance > 1 || verticalDistance < -1) {
        return false;
    }

    // Check toPosition is not occupied by player's own piece
    try {
        board.at(toPosition);
        if (board.at(toPosition)->isBlack == board.at(fromPosition)->isBlack) {
            return false;
        }
    } catch (const std::out_of_range &error) {
    }

    return true;

}

King* King::copyPiece() {
    // Return copy of King object
    return new King(this->isBlack, this->pieceName);
}

King::~King() {

}
