OBJ = bishop.o king.o knight.o pawn.o queen.o rook.o piece.o ChessBoard.o ChessGame.o
EXE = chess
CXX = g++
CPPFLAGS = -Wall -g -std=c++11

$(EXE): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: pieces/%.cpp
	$(CXX) $(CPPFLAGS) -c $<

bishop.o: pieces/bishop.h
king.o: pieces/king.h
knight.o: pieces/knight.h
pawn.o: pieces/pawn.h
queen.o: pieces/queen.h
rook.o: pieces/rook.h
piece.o: pieces/piece.h
ChessBoard.o: ChessBoard.h
ChessGame.o: ChessBoard.h

clean:
	rm *.o
