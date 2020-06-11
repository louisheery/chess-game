// Author: Louis Heery

#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <string>
#include "piece.h"

using namespace std;

class Rook : public Piece {

public:

    // Rook Piece Object Constructor: Creates new Rook Piece Object, initialises
    // piece starting conditions (isBlack = True/False, pieceName = "Rook"
    Rook(bool isBlackInput, string pieceNameInput);

    // FUNCTION: Given a current fromPosition and toPosition, function determines
    // whether the move is valid given the current setup of the board and the rules
    // which determine which moves are legal for a Rook object.
    bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition);

    // FUNCTION: Duplication function that makes a copy of the current Rook object
    // instance, and then returns a Rook Pointer that points to that object.
    Rook* copyPiece();

    // Rook Object Destructor: Removes Rook Object. Called automatically
    // once the Board object goes out of scope.
    ~Rook();
};

#endif
