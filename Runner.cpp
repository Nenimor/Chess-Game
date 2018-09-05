// Runner.cpp

#include "Runner.h"


// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Runner.
// --------------------------------------------------------------------------------------


/**
 * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
 * pieces are in the route
 * @param newRow the new row
 * @param newCol the new column
 * @param board the current playing board
 * @return
 */
int Runner::checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
{
    bool negativeRow = false, negativeCol = false;
    int currentRow, currentCol;

    // checks if the move is legal for that piece (diagonal movement)
    if (abs(newRow - _row) != abs(newCol - _col))
    {
        return EXIT_FAILURE;
    }

    // checks there are no other pieces on route
    if (newRow < _row)
    {
        negativeRow = true;
    }
    if (newCol < _col)
    {
        negativeCol = true;
    }
    currentRow = _row;
    currentCol = _col;

    while (currentRow != newRow && currentCol != newCol)
    {
        if (board[currentRow][currentCol] != nullptr && (currentRow != _row && currentCol != _col))
        {
            return EXIT_FAILURE;
        }

        if (negativeCol)
        {
            currentCol--;
        }
        else
        {
            currentCol++;
        }
        if (negativeRow)
        {
            currentRow--;
        }
        else
        {
            currentRow++;
        }
    }
    return EXIT_SUCCESS;
}

/**
* prints the piece to the board
*/
void Runner::printPiece()
{
    if (_player == WHITE)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[37;42m\u265D\33[0m";
        }
        else
        {
            std::cout << "\33[37;46m\u265D\33[0m";
        }
    }
    else if (_player == BLACK)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[30;42m\u265D\33[0m";
        }
        else
        {
            std::cout << "\33[30;46m\u265D\33[0m";
        }
    }
}