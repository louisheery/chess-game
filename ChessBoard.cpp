// Author: Louis Heery

#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard() {

  // Create new instance of Board object
  board = new Board();

  // Assign initial parameters of ChessBoard Attributes
  isWhiteTurn = true;
  hasGameEnded = false;
  isInCheck = false;

  // Initialise White Player's Pieces
  board->insert(map<string, Piece*>::value_type("A1", new Rook(false, "Rook")));
  board->insert(map<string, Piece*>::value_type("B1", new Knight(false, "Knight")));
  board->insert(map<string, Piece*>::value_type("C1", new Bishop(false, "Bishop")));
  board->insert(map<string, Piece*>::value_type("D1", new Queen(false, "Queen")));
  board->insert(map<string, Piece*>::value_type("E1", new King(false, "King")));
  board->insert(map<string, Piece*>::value_type("F1", new Bishop(false, "Bishop")));
  board->insert(map<string, Piece*>::value_type("G1", new Knight(false, "Knight")));
  board->insert(map<string, Piece*>::value_type("H1", new Rook(false, "Rook")));

  board->insert(map<string, Piece*>::value_type("A2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("B2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("C2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("D2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("E2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("F2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("G2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("H2", new Pawn(false, "Pawn")));

  // Initialise Black Player's Pieces
  board->insert(map<string, Piece*>::value_type("A7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("B7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("C7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("D7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("E7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("F7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("G7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("H7", new Pawn(true, "Pawn")));

  board->insert(map<string, Piece*>::value_type("A8", new Rook(true, "Rook")));
  board->insert(map<string, Piece*>::value_type("B8", new Knight(true, "Knight")));
  board->insert(map<string, Piece*>::value_type("C8", new Bishop(true, "Bishop")));
  board->insert(map<string, Piece*>::value_type("D8", new Queen(true, "Queen")));
  board->insert(map<string, Piece*>::value_type("E8", new King(true, "King")));
  board->insert(map<string, Piece*>::value_type("F8", new Bishop(true, "Bishop")));
  board->insert(map<string, Piece*>::value_type("G8", new Knight(true, "Knight")));
  board->insert(map<string, Piece*>::value_type("H8", new Rook(true, "Rook")));

  cout << "A new chess game is started!" << endl;

}


void ChessBoard::printRow(int row) {
  cout << "  " << row << "\t";

  for (int column = 0; column < 8; column++) {

    // First Print's Column Name
    char columnLetter = ((char) ((int) 'A' + column));

    // Calculate current grid reference
    string gridReference = string(1, columnLetter) + to_string(row);

    // Then attempt to print out piece
    try {
          string pieceName = board->at(gridReference)->pieceName;
          board->at(gridReference)->isBlack == true ? cout << "b" : cout << "w";
          cout << pieceName << "\t";// Must be a piece found to print pieceName
      } catch (const std::out_of_range &error) {
          // If No Piece Found at gridReference, print blank space
          cout << "__\t";
      }
  }
  cout << row << '\n';
}


void ChessBoard::printBoard() {
  cout << "\t";
  // Print out Column headers at top of board
  for (int column = 0; column < 8; column++) {
    cout << "   " << (char)(((int)'A') + column) << "\t";
  }
  cout << "\n";
  cout << "\t+===========================================================+" << '\n';

  // Print out each row
  for (int row = 8; row > 0; row--) {
    printRow(row);

    if (row > 1) {
      cout << "\t+-----------------------------------------------------------+  " << '\n';
    }
  }
  cout << "\t+===========================================================+" << '\n';

  cout << "\t";

  // Print out Column headers at bottom of board
  for (int column = 0; column < 8; column++) {
    cout << "  " << (char)(((int)'A') + column) << "\t";
  }
  cout << "\n";
}

void ChessBoard::submitMove(string fromPosition, string toPosition) {

  // Checks game hasn't ended -> else function returns
  if (hasGameEnded) {
    cout << "Game has Ended.\n\n" << endl;
    return;
  }

  // Checks grid positions valid, and contain a piece of the current player
  if (!isGridPositionValid(fromPosition)) {
        cout << "INVALID MOVE: " << fromPosition << " is not a valid position on the board." << endl;
        return;
    }

  if (!isGridPositionValid(toPosition)) {
      cout << "INVALID MOVE: " << toPosition << " is not a valid position on the board." << endl;
      return;
  }

  if (!isFromPositionPlayerPiece(fromPosition, isWhiteTurn)) {
    return;
  }

  // Checks that destination is not already occupied by player's own piece
  string nameOfPieceMoved = (board->at(fromPosition))->pieceName;
  if (isMoveOntoSameColorPiece(fromPosition, toPosition)) {
    cout << "INVALID MOVE: " << nameOfPieceMoved << " cannot move because " << toPosition << " is occupied by ";
    if (isWhiteTurn){
    cout << "White's";
    } else {
      cout << "Black's";
    }
    cout << " own piece." << endl;
    return;

  // Checks that Move is valid for the specific piece which is currently being moved
  // isMoveValid() is called from within the Class of the Piece Object that is currently being moved
  } else if (!((board->at(fromPosition))->isMoveValid(*board, fromPosition, toPosition))) {
    cout << "INVALID MOVE: Moving " << board->at(fromPosition)->pieceName << " from " << fromPosition << " to " << toPosition;
    cout << " does not obey the rules of Chess" << endl;
    return;
  }

    // Check to see if King is currently safe here, but would not be safe if the move occured
    if (isKingSafeHere(board, true)  && !isKingSafeHereAfterMove(fromPosition, toPosition)) {
      cout << "INVALID MOVE: " << nameOfPieceMoved << " cannot move to " << toPosition << " as King would not be safe." << endl;
      return;
    }

    // IF Above conditions have been fulfilled, then we can execute the move
  if (isWhiteTurn) {
    cout << "White's ";
  } else {
    cout << "Black's ";
  }
    cout << nameOfPieceMoved << " moves from " << fromPosition << " to " << toPosition;

    // Create pointer to the piece we are moving
    Piece *movingItem = board->at(fromPosition);

    // We already know toPosition is either empty or contains ones the opponents pieces
    // Thus: If try{} completes, then an opponents piece has been found in toPosition
    //       so we delete this piece first.
    //       If try{} doesn't complete, then destination is empty -> so we can just change
    //       position of the piece that is being moved.

    try {
      Piece* toLocationItem = board->at(toPosition);

      // Folllowing 'cout' statements only executed if opponent's piece found at toPosition
      cout << " taking ";
        if (!isWhiteTurn) {
        cout << "White's ";
        } else {
        cout << "Black's ";
        }
        cout << toLocationItem->pieceName;
      delete toLocationItem; // delete opponent's piece
      board->at(toPosition) = movingItem; // Add moving item to the toPosition
    } catch (const std::out_of_range &error) {
      board->insert(map<string,Piece*>::value_type(toPosition,movingItem));
    }

    cout << "\n\n";
    board->erase(fromPosition); // erase Map item of original piece's position

    // Default back to is in check being false, as this will be checked
    // by the gameCanContinue() function
    isInCheck = false;

    // Check if game can continue (i.e. no stalemate or checkmate exists)
    if (!gameCanContinue()) {
      hasGameEnded = true; // if game can't continue -> set game has ended variable
    }

    // Switch which player's turn it is
    if (isWhiteTurn) {
      isWhiteTurn = false;
    } else {
      isWhiteTurn = true;
    }

    cout << "\n" << endl;


}

bool ChessBoard::gameCanContinue() {

  // Checks whether opponent's king is now in check
  // False parameter of isKingSafeHere function indicates we are referring to the
  // opponent, not the player who has just moved one of their pieces
  if (!isKingSafeHere(board, false)) {
    isInCheck = true;
  }

  // IF: the other player can still play a move, which results in them no longer
  // being in 'Check' then only print out that they are in check.
  if (isValidMoveExist()) {

    if (isInCheck) {
        if (isWhiteTurn) {
      cout << "Black is in ";
    } else {
      cout << "White is in ";
    }

    cout << "check." << endl;

    }

  }

  // ELSE: There are no valid moves the opponent can play
  // MEANING THAT: (a) The opponent is checkmate -- if there king is in check
  //               (b) The opponent is stalemate -- if there king is not in check
  if (!isValidMoveExist()) {

    if (isInCheck) {
          if (isWhiteTurn) {
          cout << "Black is in ";
        } else {
          cout << "White is in ";
        }

      cout << "checkmate";
    } else {
            if (!isWhiteTurn) {
            cout << "Black is in ";
          } else {
            cout << "White is in ";
          }
      cout << "stalemate";
    }

    cout << ". Game has Ended.\n" << endl;
    printBoard();
    cout << "\n\n––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    return false;
  }

  // Reprint out board after every turn
  printBoard();
  if (isWhiteTurn == true)
  {
    cout << "\n\n";
  } else {
    cout << "\n\n––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
  }
  return true;
}

bool ChessBoard::isValidMoveExist() {

  // Iterator used to cycle through all the items which exist in the Map
  map<string,Piece*>::iterator boardItem;

  // Loop through all pieces, until end of Map is reached
  for (boardItem = board->begin(); boardItem != board->end(); boardItem++) {

    string currentItemLocation = boardItem->first; // Stores item location
    Piece* currentItem = boardItem->second; // Stores pointer to piece at that location

    // If the current item is of the opposite colour to the current player who's turn it is:
    if (currentItem->isBlack == isWhiteTurn) {

      // Cycle through all squares on the board
      for (char i = 'A'; i <= 'H'; i++) {
        for (char j = '1'; j <= '8'; j++) {
          string destination = string(1, i) + string(1, j);

          // Look whether moving the current piece to any of these positions is a valid move
          if (currentItem->isMoveValid(*board, currentItemLocation, destination)) {

            // If move is valid -> then we can check if King is safe after this move occurs

            // First make a copy of the current board -> then execute current move
            Board* copyOfBoard = copyBoard(board);
            Piece* killedPiece = killPiece(copyOfBoard, currentItemLocation, destination);

            bool isMoveValid = isKingSafeHere(copyOfBoard, false);

            // Remove piece which was removed from board from the Map
            delete killedPiece;

            // Clean up and delete the copy of the board we made
            cleanBoard(copyOfBoard);

            if (isMoveValid) {
              return true; // Returns true if the King remained safe after move was made
            }
          }
        }
      }
    }
  }

  // Otherwise, if no moves are valid -> then return false
  return false;

}

bool ChessBoard::isGridPositionValid(string gridPosition) {

  // Checks Grid position first character is a character between 'A' and 'H'
  if (((int) gridPosition.at(0)) < 65 || (((int) gridPosition.at(0))) > 72) {
    return false;
  }

  // Checks grid position second character is a character between '1' and '8'
  if (((int) gridPosition.at(1)) < 49 || (((int) gridPosition.at(1)) > 56)) {

    return false;
  }

  return true;
}

bool ChessBoard::isMoveOntoSameColorPiece(string fromPosition, string toPosition) {

  // Try function only executes to completion if there is a piece at the toPosition
  try {
    board->at(toPosition);

    // If above statement executes, we check if toPosition piece is same colour as fromPosition piece
    if ((board->at(fromPosition))->isBlack == (board->at(toPosition))->isBlack) {
      return true;
    } else {
      return false;
    }
  } catch (const std::out_of_range &error) {
    return false; // Else, no piece has been found -> so move isn't onto same colour piece
  }
}

bool ChessBoard::isFromPositionPlayerPiece(string fromPosition, bool isWhiteTurn) {

  // Try function only executes to completion if there is a piece at the toPosition
  try {
    board->at(fromPosition)->pieceName;

    // If above statement executes, check if piece is not equal to the current players colour
    if ((board->at(fromPosition))->isBlack != isWhiteTurn) {
      return true;
    } else {
      cout << "It is not ";

      if (board->at(fromPosition)->isBlack) {
        cout << "Black's";
      } else {
        cout << "White's";
      }

      cout << " turn to move!" << endl;

      return false;
    }
  } catch (const std::out_of_range &error) {
    cout << "There is no piece at position " << fromPosition << "!" << endl;
    return false; // Else, no piece found -> so fromPosition doesn't contain player's piece

  }

}

string ChessBoard::findPlayerKingPosition(const Board* board, const bool playerOwnPiece) {

  // Create new iterator
  //map<string,Piece*>::const_iterator boardItem;
  Board::const_iterator boardItem;

  // Loop through all pieces on the board i.e. stored in the Map
  for (boardItem = board->cbegin(); boardItem != board->cend(); boardItem++) {
    string currentItemLocation = boardItem->first;
    Piece* currentItem = boardItem->second;

    // If we are searching for the opponent's King (i.e. if playerOwnPiece == false)
    if (playerOwnPiece == false && (currentItem->isBlack == isWhiteTurn) && (currentItem->pieceName == "King")) {
      return currentItemLocation;
    }

    // If we are searching for the current player's King (i.e. if playerOwnPiece == true)
    else if (playerOwnPiece == true && (currentItem->isBlack != isWhiteTurn) && (currentItem->pieceName == "King")) {
      return currentItemLocation;
    }

  }

  cout << "!^*£!(£&!£&" << endl;
  return "ajskldjaskldjaklsdjsadjkljasd";
}

bool ChessBoard::isKingSafeHere(Board* board, bool playerOwnPiece) {

  string playerKingPosition = findPlayerKingPosition(board, playerOwnPiece);

  // Create new iterator
  map<string,Piece*>::const_iterator boardItem;

  // Loop through all pieces on the board i.e. stored in the Map
  for (boardItem = board->begin(); boardItem != board->end(); boardItem++) {

    string currentItemLocation = boardItem->first;
    Piece* currentItem = boardItem->second;

    // If we are checking whether opponent's King is safe.
    if ((playerOwnPiece == false) && (currentItem->isBlack != isWhiteTurn) && (currentItem->isMoveValid(*board, currentItemLocation, playerKingPosition))) {
      return false;
    }

    // If we are searching whether current player's King is safe
    else if ((playerOwnPiece == true) && (currentItem->isBlack == isWhiteTurn) && (currentItem->isMoveValid(*board, currentItemLocation, playerKingPosition))) {
      return false;
    }

  }

  return true;

}

bool ChessBoard::isKingSafeHereAfterMove(string opponentPieceFromPosition, string opponentPieceToPosition) {

  // First create copy of board, and temporary item to store moved piece
  Board* copyOfBoard = copyBoard(board);
  Piece* movedPieceTemp = copyOfBoard->at(opponentPieceFromPosition);

  // Try is only executed if there is a piece currently occuping the toPosition
  try {
    Piece* opponentPieceToPositionPiece = copyOfBoard->at(opponentPieceToPosition);
    delete opponentPieceToPositionPiece; // Delete opponent piece if found

    copyOfBoard->at(opponentPieceToPosition) = movedPieceTemp; // Move piece in copy of board

  // Catch if there is no piece occupying toPosition -> then just insert moving piece
  } catch (const out_of_range &error) {
    copyOfBoard->insert(map<string,Piece*>::value_type(opponentPieceToPosition,movedPieceTemp));
  }

  copyOfBoard->erase(opponentPieceFromPosition); // Erase original piece at fromPosition

  // Check if the king still safe, i.e. after move has been executed
  if (!isKingSafeHere(copyOfBoard, true)) {
    cleanBoard(copyOfBoard); // clean Board copy
    return false;
  }

  cleanBoard(copyOfBoard); // clean Board copy
  return true;

}

void ChessBoard::resetBoard() {

  cleanBoard(board); // Remove all pieces from current board
  board = new Board; // create new Board object instance

  // Reset members of ChessBoard to default parameters
  isWhiteTurn = true;
  hasGameEnded = false;
  isInCheck = false;

  // Set the position of White Player's pieces
  board->insert(map<string, Piece*>::value_type("A1", new Rook(false, "Rook")));
  board->insert(map<string, Piece*>::value_type("B1", new Knight(false, "Knight")));
  board->insert(map<string, Piece*>::value_type("C1", new Bishop(false, "Bishop")));
  board->insert(map<string, Piece*>::value_type("D1", new Queen(false, "Queen")));
  board->insert(map<string, Piece*>::value_type("E1", new King(false, "King")));
  board->insert(map<string, Piece*>::value_type("F1", new Bishop(false, "Bishop")));
  board->insert(map<string, Piece*>::value_type("G1", new Knight(false, "Knight")));
  board->insert(map<string, Piece*>::value_type("H1", new Rook(false, "Rook")));

  board->insert(map<string, Piece*>::value_type("A2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("B2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("C2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("D2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("E2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("F2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("G2", new Pawn(false, "Pawn")));
  board->insert(map<string, Piece*>::value_type("H2", new Pawn(false, "Pawn")));

  // Set the position of Black Player's pieces
  board->insert(map<string, Piece*>::value_type("A7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("B7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("C7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("D7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("E7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("F7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("G7", new Pawn(true, "Pawn")));
  board->insert(map<string, Piece*>::value_type("H7", new Pawn(true, "Pawn")));

  board->insert(map<string, Piece*>::value_type("A8", new Rook(true, "Rook")));
  board->insert(map<string, Piece*>::value_type("B8", new Knight(true, "Knight")));
  board->insert(map<string, Piece*>::value_type("C8", new Bishop(true, "Bishop")));
  board->insert(map<string, Piece*>::value_type("D8", new Queen(true, "Queen")));
  board->insert(map<string, Piece*>::value_type("E8", new King(true, "King")));
  board->insert(map<string, Piece*>::value_type("F8", new Bishop(true, "Bishop")));
  board->insert(map<string, Piece*>::value_type("G8", new Knight(true, "Knight")));
  board->insert(map<string, Piece*>::value_type("H8", new Rook(true, "Rook")));

  cout << "A new chess game is started!" << endl;
}

Board* ChessBoard::copyBoard(Board* originalBoard) {

  // First create pointer to new instance of Board object
  Board* copyBoard = new Board;

  // Then make new iterator item
  map<string, Piece*>::iterator boardItem;

  // Then cycle through  each item of original board and copy each item to the copy of board Map
  for (boardItem = board->begin(); boardItem != board->end(); boardItem++) {
    copyBoard->insert(map<string, Piece*>::value_type(boardItem->first, boardItem->second->copyPiece()));
  }

  return copyBoard;

}

void ChessBoard::cleanBoard(Board* boardToClean) {

  // Create iterator item
  map<string,Piece*>::iterator boardItem;

  // Loop through all items in Board Map, and delete each one in turn
  for (boardItem = boardToClean->begin(); boardItem != boardToClean->end(); boardItem++) {
    delete boardItem->second;
  }

  delete boardToClean;

}

Piece* ChessBoard::killPiece(Board* board, string fromLocation, string toLocation) {

  Piece *pieceMoving = board->at(fromLocation); // Create pointer to piece that is moving
  Piece *pieceBeingKilled; // Create pointer to piece that is being killed (i.e. removed from board)

  // Try executes if piece is found at toLocation
  try {
    pieceBeingKilled = board->at(toLocation);
    board->at(toLocation) = pieceMoving; // Change piece that is found at to location

  // Else if no piece found at toLocation
  } catch (const std::out_of_range &error) {
    pieceBeingKilled = NULL; // Set pointer to null
    board->insert(map<string,Piece*>::value_type(toLocation,pieceMoving)); // Insert piece at toPosition
  }

  board->erase(fromLocation); // Erase original piece at from location
  return pieceBeingKilled;
}

ChessBoard::~ChessBoard() {

}
