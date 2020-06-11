// Author: Louis Heery

#ifndef KING_H
#define KING_H

#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <string>
#include "piece.h"

using namespace std;

class King : public Piece {

public:

    // King Piece Object Constructor: Creates new King Piece Object, initialises
    // piece starting conditions (isBlack = True/False, pieceName = "King"
    King(bool isBlackInput, string pieceNameInput);

    // FUNCTION: Given a current fromPosition and toPosition, function determines
    // whether the move is valid given the current setup of the board and the rules
    // which determine which moves are legal for a King object.
    bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition);

    // FUNCTION: Duplication function that makes a copy of the current King object
    // instance, and then returns a King Pointer that points to that object.
    King* copyPiece();

    // King Object Destructor: Removes King Object. Called automatically
    // once the Board object goes out of scope.
    ~King();

};

#endif
