// Author: Louis Heery

#include "knight.h"

using namespace std;

Knight::Knight(bool isBlackInput, string pieceNameInput) : Piece(isBlackInput, pieceNameInput) {

}

bool Knight::isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) {

    // Calculate horizontal and vertical distance of the current move
    int verticalDistance = (int) (toPosition.at(1)) - (fromPosition.at(1));
    int horizontalDistance = (int) (toPosition.at(0)) - (fromPosition.at(0));

    // Check move is allowed for Knight
    if (horizontalDistance == 0 && verticalDistance == 0) {
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

    // Check Knight is moving in a L-spaced sequence
    if (!((abs(verticalDistance) == 1 && abs(horizontalDistance) == 2) || (abs(verticalDistance) == 2 && abs(horizontalDistance) == 1))) {
        return false;
    }

    return true;

}


Knight* Knight::copyPiece() {
    // Return copy of Knight object
    return new Knight(this->isBlack, this->pieceName);
}


Knight::~Knight() {

}
