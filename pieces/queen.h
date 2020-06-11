// Author: Louis Heery

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <string>
#include "piece.h"

using namespace std;

class Queen : public Piece {

public:

    // Queen Piece Object Constructor: Creates new Queen Piece Object, initialises
    // piece starting conditions (isBlack = True/False, pieceName = "Queen"
    Queen(bool isBlackInput, string pieceNameInput);

    // FUNCTION: Given a current fromPosition and toPosition, function determines
    // whether the move is valid given the current setup of the board and the rules
    // which determine which moves are legal for a Queen object.
    bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition);

    // FUNCTION: Duplication function that makes a copy of the current Queen object
    // instance, and then returns a Queen Pointer that points to that object.
    Queen* copyPiece();

    // Queen Object Destructor: Removes Queen Object. Called automatically
    // once the Board object goes out of scope.
    ~Queen();

};

#endif
