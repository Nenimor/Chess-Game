CCP=g++
CFLAGS=-c -Wextra -Wall -Wvla -std=c++17 -pthread -g -DNDEBUG 

all:chess


chess:GameBoard.o GamePiece.o Castle.o Horse.o King.o Queen.o Runner.o Soldier.o chess.o
	$(CCP) $^ -o $@

%.o:%.cpp
	$(CCP) $(CFLAGS) $< -o $@

clean:
	rm -f chess *.o

valg: chess
	valgrind --leak-check=full --show-possibly-lost=yes --show-reachable=yes --undef-value-errors=yes ./chess valgrind_output.txt

TAR_FILES = GameBoard.h GamePiece.h Castle.h Horse.h King.h Queen.h Runner.h Soldier.h chess.cpp GameBoard.cpp GamePiece.cpp Castle.cpp Horse.cpp King.cpp Queen.cpp Runner.cpp Soldier.cpp README
tar:
	tar -cvf $ ex2.tar $(TAR_FILES)

.PHONY:all , clean ,valg, tar
