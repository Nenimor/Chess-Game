cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES chess.cpp GameBoard.cpp GameBoard.h GamePiece.cpp GamePiece.h Queen.cpp Queen.h King.cpp King.h Horse.cpp Horse.h Soldier.cpp Soldier.h Runner.cpp Runner.h Castle.cpp Castle.h)
add_executable(Ex2 ${SOURCE_FILES})