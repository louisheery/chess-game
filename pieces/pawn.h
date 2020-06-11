// Author: Louis Heery

#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <string>
#include "piece.h"

using namespace std;

class Pawn : public Piece {

public:

    // Pawn Piece Object Constructor: Creates new Pawn Piece Object, initialises
    // piece starting conditions (isBlack = True/False, pieceName = "Pawn"
    Pawn(bool isBlackInput, string pieceNameInput);

    // FUNCTION: Given a current fromPosition and toPosition, function determines
    // whether the move is valid given the current setup of the board and the rules
    // which determine which moves are legal for a Pawn object.
    bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition);

    // FUNCTION: Duplication function that makes a copy of the current Pawn object
    // instance, and then returns a Pawn Pointer that points to that object.
    Pawn* copyPiece();

    // Pawn Object Destructor: Removes Pawn Object. Called automatically
    // once the Board object goes out of scope.
    ~Pawn();

};

#endif
