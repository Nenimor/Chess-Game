// Castle.cpp

#include "Castle.h"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Castle.
// --------------------------------------------------------------------------------------


/**
 * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
 * pieces are in the route
 * @param newRow the new row
 * @param newCol the new column
 * @param board the current playing board
 * @return
 */
int Castle::checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
{
    bool negativeRow = false, negativeCol = false, directionRow = false, directionCol = false;
    int currentRow, currentCol;

    // checks if the move is legal for that piece (horizontal\perpendicular movement)
    if (_row != newRow && _col != newCol)
    {
        return EXIT_FAILURE;
    }
    // first check the direction of then route the check for pieces in the route
    if (_row != newRow)
    {
        directionRow = true;
        if (newRow < _row)
        {
            negativeRow = true;
        }
    }
    if (_col != newCol)
    {
        directionCol = true;
        if (newCol < _col)
        {
            negativeCol = true;
        }
    }

    currentRow = _row;
    currentCol = _col;
    while (currentRow != newRow && currentCol != newCol)
    {
        if (board[currentRow][currentCol] != nullptr && (currentRow != _row && currentCol != _col))
        {
            return EXIT_FAILURE;
        }

        if (directionCol)
        {
            if (negativeCol)
            {
                currentCol--;
            }
            else
            {
                currentCol++;
            }
        }
        else if (directionRow)
        {
            if (negativeRow)
            {
                currentRow--;
            }
            else
            {
                currentRow++;
            }
        }
    }

    return EXIT_SUCCESS;
}

/**
* prints the piece to the board
*/
void Castle::printPiece()
{
    if (_player == WHITE)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[37;42m\u265C\33[0m";
        }
        else
        {
            std::cout << "\33[37;46m\u265C\33[0m";
        }
    }
    else if (_player == BLACK)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[30;42m\u265C\33[0m";
        }
        else
        {
            std::cout << "\33[30;46m\u265C\33[0m";
        }
    }
}

/**
 * Moves the piece to a new position
 * @param row the new row
 * @param col the new column
 */
void Castle::move(int row, int col)
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
bool Castle::hasMoved() const
{
    return _hasMoved;
}
