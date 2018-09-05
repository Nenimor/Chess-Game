#ifndef EX2_GAMEBOARD_H
#define EX2_GAMEBOARD_H

#include "GamePiece.h"
#include "Soldier.h"
#include "Runner.h"
#include "King.h"
#include "Castle.h"
#include "Queen.h"
#include "Horse.h"
#include <iostream>
#define BOARD_DIM 8
#define WHITE 1
#define BLACK 2
#define ASCII_NORM 65
#define KING_CASTLE_COL 7
#define QUEEN_CASTLE_COL 0
#define CASTLING_KING_SIDE "o-o"
#define CASTLING_QUEEN_SIDE "o-o-o"
#define GREEN_SPACE "\33[0;42m \33[0m"
#define BLUE_SPACE "\33[0;46m \33[0m"
#define ILLEGAL_MOVE "\33[37;41millegal move\33[0m\n"
#define MOVE_INPUT_MSG ": Please enter your move:\n"
#define CHECK_WARNING_MSG "\33[37;41mCheck!\33[0m\n"

using namespace std;

/**
 * a Class which represents a Chess Game board
 */
class GameBoard
{
private:
    int _currentTurn; /** a current turn indicator*/
    string _player1Name; /** holds player 1 name */
    string _player2Name; /** holds player 2 name */
    int _whiteKingPos[2]; /** holds player 1 king's position */
    int _blackKingPos[2]; /** holds player 2 king's position */
    /** an array of pointers which represents the board */
    GamePiece* _board[BOARD_DIM][BOARD_DIM] = {{nullptr}};

    /**
    * checks if a given index exceeds the board borders
    * @param index index to check
    * @return 0 if the given index is a valid index in the board, 1 otherwise
    */
    int _isIndexLegal(int index);

    /**
    * checks if a specific position is threatened by a queen, castle or a King (vertical &
    * horizontal check)
    * @param posToCheck - the current position to check
    * @return 1 if the position is threatened, 0 otherwise
    */
    int _checkVerticHoriz(int posToCheck[2]);

    /**
    * checks if a specific position is threatened by a queen, runner or a King (diagonal check)
    * @param kingPos - the current position to check
    * @return 1 if the position is threatened, 0 otherwise
    */
    int _checkDiagonal(int posToCheck[2]);

    /**
    * checks if a specific position is threatened by a soldier
    * @param PosToCheck - the current position to check
    * @return 1 if the position is threatened, 0 otherwise
    */
    int _soldierThreat(int posToCheck[2]);

    /**
    * this method checks if a couple of indices in the board contains a horseman which threathens
    * the king
    * @param rowToCheck row index in the board
    * @param colToCheck col index in the board
    * @return 1 if the king is threathened, 0 otherwise
    */
    int _checkHorseIndices(int rowToCheck, int colToCheck);

    /**
    * checks if a specific position is threatened by a horseman
    * @param kingPos - the current position to check
    * @return 1 if the position is threatened, 0 otherwise
    */
    int _horseThreat(int posToCheck[2]);

    /**
    * performs all legality checks of a desired move, besides if it exposes the king
    * @param move - a string represents a move as given by the user
    * @return 0 if the move is legal, 1 otherwise
    */
    int _isMoveLegal(string move);

    /**
    * checks if the current player's king is exposed
    * @return 1 if the king is exposed, 0 otherwise
    */
    int _isKingThreatened();

    /**
    * this method gets position indices, and returns whether this position is threatened or not
    * @param rowPos index of the row
    * @param colPos index of the col
    * @return 1 if this position is threatened, 0 otherwise
    */
    int _isPositionThreatened(int rowPos, int colPos);

    /**
    * this method performs a castling by king side
    * @return 0 if castling was possible and performed, 1 otherwise
    */
    int _castlingKingSide();

    /**
    * this method performs a castling by queen side
    * @return 0 if castling was possible and performed, 1 otherwise
    */
    int _castlingQueenSide();

public:


    /**
    * a constructor which initializes a game board
    */
    GameBoard();

    /**
    * this method performs a move after legality check
    * @param move - a string represents a move, as given by the user
    * @return 0 if the move is legal and performed, 1 otherwise
    */
    int makeMove(string move);

    /**
    * this method prints the board
    */
    void printBoard();

    /**
    * this method cleans the board
    */
    void cleanBoard();

    /**
    * this method checks at the beginning of a turn if the player's king is exposed and warns him
    * if so
    * @return 1 if the king is exposed, 0 otherwise
    */
    int warnIfCheck();

    /**
    * this method receives a move as input from user
    * @return string represents the desired move
    */
    string getMove();

    /**
    * this method changes the current turn to the other player
    */
    void changeTurn();

    /**
    * changes turns, and checks if the current player is in an unavoidable situation, and losing
    * @return 0 and declare winner if there is one, returns 1 if there is no
    */
    int checkWinner();

};


#endif //EX2_GAMEBOARD_H
