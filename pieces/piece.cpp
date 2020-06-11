// Author: Louis Heery

#include "piece.h"

using namespace std;

Piece::Piece(bool isBlackInput, string pieceNameInput) : isBlack(isBlackInput), pieceName(pieceNameInput), isFirstMove(true) {

}

Piece::~Piece() {

}
