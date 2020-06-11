// Author: Louis Heery

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <string>
#include "piece.h"

using namespace std;

class Bishop : public Piece {

public:

    // Bishop Piece Object Constructor: Creates new Bishop Piece Object, initialises
    // piece starting conditions (isBlack = True/False, pieceName = "Bishop"
    Bishop(bool isBlackInput, string pieceNameInput);

    // FUNCTION: Given a current fromPosition and toPosition, function determines
    // whether the move is valid given the current setup of the board and the rules
    // which determine which moves are legal for a Bishop object.
    bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition);

    // FUNCTION: Duplication function that makes a copy of the current Bishop object
    // instance, and then returns a Bishop Pointer that points to that object.
    Bishop* copyPiece();

    // Bishop Object Destructor: Removes Bishop Object. Called automatically
    // once the Board object goes out of scope.
    ~Bishop();

};

#endif
