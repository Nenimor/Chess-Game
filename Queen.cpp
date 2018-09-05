// Queen.cpp

#include "Queen.h"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Queen.
// --------------------------------------------------------------------------------------

/**
 * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
 * pieces are in the route
 * @param newRow the new row
 * @param newCol the new column
 * @param board the current playing board
 * @return
 */
int Queen::checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
{
    bool negativeRow = false, negativeCol = false, directionRow = false, directionCol = false;
    int currentRow, currentCol;

    // checks if the move is legal for that piece (diagonal and horizontal\perpendicular movement)
    if ((abs(newRow - _row) != abs(newCol - _col)) && (_row != newRow && _col != newCol))
    {
        return EXIT_FAILURE;
    }

    // first check the direction of the route then check for pieces in the route
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
            std::cout << "error at the checking paws at route"; //TODO delete after checking
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
        if (directionRow)
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
void Queen::printPiece()
{
    if (_player == WHITE)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[37;42m\u265B\33[0m";
        }
        else
        {
            std::cout << "\33[37;46m\u265B\33[0m";
        }
    }
    else if (_player == BLACK)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[30;42m\u265B\33[0m";
        }
        else
        {
            std::cout << "\33[30;46m\u265B\33[0m";
        }
    }
}

