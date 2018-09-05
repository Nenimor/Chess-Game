// King.cpp

#include "King.h"


// --------------------------------------------------------------------------------------
// This file contains the implementation of the class King.
// --------------------------------------------------------------------------------------

#define BOUND 1


/**
 * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
 * pieces are in the route
 * @param newRow the new row
 * @param newCol the new column
 * @param board the current playing board
 * @return
 */
int King::checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
{
    (void)board;
    // checks if the move is legal for that piece
    if ((abs(newRow - _row) != abs(newCol - _col)) && (abs(newRow - _row) != BOUND) &&
        (_row != newRow && _col !=newCol))
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
* prints the piece to the board
*/
void King::printPiece()
{
    if (_player == WHITE)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[37;42m\u265A\33[0m";
        }
        else
        {
            std::cout << "\33[37;46m\u265A\33[0m";
        }
    }
    else if (_player == BLACK)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[30;42m\u265A\33[0m";
        }
        else
        {
            std::cout << "\33[30;46m\u265A\33[0m";
        }
    }
}

/**
 * Moves the piece to a new position
 * @param row the new row
 * @param col the new column
 */
void King::move(int row, int col)
{
    if (!_hasMoved)
    {
        _hasMoved = true;
    }
    GamePiece::move(row, col);
}

// ------------------ Access method ------------------------
/**
 * returns true if the piece has already moved once, false otherwise
 * @return returns true if the piece has already moved once, false otherwise
 */
bool King::hasMoved() const
{
    return _hasMoved;
}

