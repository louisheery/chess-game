// Author: Louis Heery

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <exception>
#include <vector>
#include <map>
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"

using namespace std;

typedef map<string, Piece*> Board;

class ChessBoard {

private:

  Board* board; // Pointer to Board object
  bool isWhiteTurn; // Whether it is White's turn (TRUE) or Black's turn (FALSE);
  bool hasGameEnded; // Whether the game has ended.
  bool isInCheck; // Whether one of the players is in Check state.

  // FUNCTION: Prints a single row of the current ChessBoard 'board'.
  void printRow(int row);

  // FUNCTION: Determines whether the game can continue or not.
  // OUTPUT = TRUE: If No checkmate/stalemate has been reached i.e. isValidMovesExist() = true
  // OUTPUT = FALSE: If Checkmate or Stalemate has been reached.
  bool gameCanContinue();

  // FUNCTION: Determines whether there are Valid moves that can be played by current player.
  // OUTPUT = TRUE: If possible moves exist that keep the King safe.
  // OUTPUT = FALSE: If no possible moves can be played that keep the King safe.
  bool isValidMoveExist();

  // FUNCTION: Determines whether a given grid reference is valid on ChessBoard
  bool isGridPositionValid(string gridPosition);

  // FUNCTION: Determines whether player is trying to move a piece onto another of their pieces
  bool isMoveOntoSameColorPiece(string fromPosition, string toPosition);

  // FUNCTION: Determines if the Player is moving their own piece.
  bool isFromPositionPlayerPiece(string fromPosition, bool isWhiteTurn);

  // FUNCTION: Finds position of King on ChessBoard of current player.
  // OUTPUT: Grid reference of King location.
  string findPlayerKingPosition(const Board* board, const bool playerOwnPiece);

  // FUNCTION: Determines whether in the current state of the Board, is King safe.
  // INPUT: Board, and whether we are determining is Player's king or their opponents king is safe.
  bool isKingSafeHere(Board* board, bool playerOwnPiece);

  // FUNCTION: Determines whether if after the specified move is made, is the King still safe.
  // INPUT: The FromPosition and ToPosition of the Piece which is due to be moved.
  bool isKingSafeHereAfterMove(string opponentPieceFromPosition, string opponentPieceToPosition);

  // FUNCTION: Duplicates the current ChessBoard, and returns a Copy of It.
  Board* copyBoard(Board* originalBoard);

  // FUNCTION: Removes all Pieces from Board.
  void cleanBoard(Board* boardToClean);

  // FUNCTION: Moves Piece at Location 'fromLocation' to Location 'toLocation, and removes
  // the piece previously occupying the toLocation.
  // OUTPUT: Returns Pointer to the Piece that has been removed, so it can be later deleted.
  Piece* killPiece(Board* board, string fromLocation, string toLocation);

  // FUNCTION: Determines whether a current square is empty or not.
  bool emptySpace(const string source);

public:

  // ChessBoard Object Constructor: Creates new Board Map Object, initialises game starting
  // conditions (isWhiteTurn = True, hasGameEnded = False, isInCheck = False), and adds all
  // the starting pieces to the boards in their starting locations.
  ChessBoard();

  // FUNCTION: User accessable function for submitting Chess Moves to the Game.
  // Within this function, each move is evaluated to check it is valid and allowed given the
  // current situation of the game.
  // OUTPUT if Move Successful = Message reiterating Move played & any piece killed in process.
  // OUTPUT if Move Unsuccessful = Message explaining why Move was not valid or allowed.
  void submitMove(string fromPosition, string toPosition);

  // FUNCTION: Which prints out the current state of the board to the Terminal.
  void printBoard();

  // FUNCTION: Calls the cleanBoard() Function on the current board, and then
  // creates a new Board object (which is automatically initialised using ChessBoard constructor)
  void resetBoard();

  // ChessBoard Object Destructor: Removes Pointers and Objects contained within the current
  // ChessBoard instance. Is called automatically once the Board object goes out of scope.
  ~ChessBoard();

};
