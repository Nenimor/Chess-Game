// Soldier.cpp

#include "Soldier.h"


// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Point.
// --------------------------------------------------------------------------------------


#define BIG_STEP 2
#define SMALL_STEP 1

/**
 * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
 * pieces are in the route
 * @param newRow the new row
 * @param newCol the new column
 * @param board the current playing board
 * @return
 */
int Soldier::checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
{
    // checks if the move is legal for that piece
    if (_player == BLACK)
    {
        if (!hasMoved())
        {
            if (board[newRow][newCol] == nullptr)
            {
                if ((_row + BIG_STEP != newRow && _row + SMALL_STEP != newRow) || _col != newCol)
                {
                    return EXIT_FAILURE;
                }
            }
            else if (board[newRow][newCol]->getPlayerNum() == WHITE)
            {
                if ((newRow - _row) != abs(newCol - _col) || (newRow -_row) != SMALL_STEP)
                {
                    return EXIT_FAILURE;
                }
            }
        }
        else if (board[newRow][newCol] == nullptr)
        {
            if (_row + SMALL_STEP != newRow || _col != newCol)
            {
                return EXIT_FAILURE;
            }
        }
        else if (board[newRow][newCol]->getPlayerNum() == WHITE)
        {
            if ((newRow - _row) != abs(newCol - _col) || (newRow -_row) != SMALL_STEP)
            {
                return EXIT_FAILURE;
            }
        }
    }

    if (_player == WHITE)
    {
        if (!hasMoved())
        {
            if (board[newRow][newCol] == nullptr)
            {
                if ((_row - BIG_STEP != newRow && _row - SMALL_STEP != newRow) || _col != newCol)
                {
                    return EXIT_FAILURE;
                }
            }
            else if (board[newRow][newCol]->getPlayerNum() == BLACK)
            {
                if ((_row - newRow) != abs(newCol - _col) || (_row - newRow) != SMALL_STEP)
                {
                    return EXIT_FAILURE;
                }
            }
        }
        else if (board[newRow][newCol] == nullptr)
        {
            if (_row - SMALL_STEP != newRow || _col != newCol)
            {
                return EXIT_FAILURE;
            }
        }
        else if (board[newRow][newCol]->getPlayerNum() == BLACK)
        {
            if ((_row - newRow) != abs(newCol - _col) || (_row - newRow) != SMALL_STEP)
            {
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

/**
* prints the piece to the board
*/
void Soldier::printPiece()
{
    if (_player == WHITE)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[37;42m\u265F\33[0m";
        }
        else
        {
            std::cout << "\33[37;46m\u265F\33[0m";
        }
    }
    else if (_player == BLACK)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[30;42m\u265F\33[0m";
        }
        else
        {
            std::cout << "\33[30;46m\u265F\33[0m";
        }
    }
}


/**
 * Moves the piece to a new position
 * @param row the new row
 * @param col the new column
 */
void Soldier::move(int row, int col)
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
bool Soldier::hasMoved() const
{
    return _hasMoved;
}
