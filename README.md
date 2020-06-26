# Chess Game

A C++ application which lets players compete in games of Chess.

![alt text](https://github.com/louisheery/chess-game/blob/master/chess-game-screenshots.png)

## How to Run Chess Game
### 
```
$ cd chess-game
$ make
$ ./chess
```

## How to Use Chess Game within another Application
1. Copy chess-game into application dictionary
2. Import amd utilise ChessBoard object
```
#include "ChessBoard.h"
...
int main() {
  ...
  ChessBoard chessBoard = ChessBoard(); // Instantiate ChessBoard Object
  cout << chessBoard << endl; // Print board
  cb.submitMove([START LOCATION], [END LOCATION]); // Play a Move
 ...
}
```
