// Author: Louis Heery

#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <string>
#include "piece.h"

using namespace std;

class Knight : public Piece {

public:

    // Knight Piece Object Constructor: Creates new Knight Piece Object, initialises
    // piece starting conditions (isBlack = True/False, pieceName = "Knight"
    Knight(bool isBlackInput, string pieceNameInput);

    // FUNCTION: Given a current fromPosition and toPosition, function determines
    // whether the move is valid given the current setup of the board and the rules
    // which determine which moves are legal for a Knight object.
    bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition);

    // FUNCTION: Duplication function that makes a copy of the current Knight object
    // instance, and then returns a Knight Pointer that points to that object.
    Knight* copyPiece();

    // Knight Object Destructor: Removes Knight Object. Called automatically
    // once the Board object goes out of scope.
    ~Knight();

};

#endif
