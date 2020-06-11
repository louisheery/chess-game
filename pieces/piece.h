// Author: Louis Heery

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <exception>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include <cmath>

using namespace std;

class Piece {

    public:

        bool isBlack;   // Whether object is Black (FALSE, if White)
        string pieceName; // Name of Piece
        bool isFirstMove; // Whether it is the Piece's first move

        // Piece Object Constructor: Creates new Piece Object, initialises
        // piece starting conditions (isBlack = True/False, pieceName = "__").
        Piece(bool isBlackInput, string pieceNameInput);

        // Piece Virtual isMoveValid Function.
        // Requires all Derived Objects to have this function implemented.
        virtual bool isMoveValid(map<string, Piece*> board, string fromPosition, string toPosition) = 0;

        // Piece Virtual copyPiece() Object Duplication Function.
        // Requires all Derived Objects to have a CopyPiece() Function
        virtual Piece* copyPiece() = 0;

        // Piece Virtual Object Destructor Function.
        // Requires all Derived Objects to have a Destructor.
        virtual ~Piece() = 0;

};

#endif
