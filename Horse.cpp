// Horse.cpp

#include "Horse.h"


// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Horse.
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
int Horse::checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM])
{
    (void)board;
    // checks if the move is legal for that piece
    bool rowBigStep = false;
    bool colBigStep = false;

    // checks where the big step - row or column, else move is illegal for horse
    if (_row + BIG_STEP == newRow || _row - BIG_STEP == newRow)
    {
        rowBigStep = true;
    }
    else if (_col + BIG_STEP == newCol || _col - BIG_STEP == newCol)
    {
        colBigStep = true;
    }
    else
    {
        return EXIT_FAILURE;
    }

    // checks if the perpendicular direction of the big step is a small step
    if (colBigStep)
    {
        if (_row + SMALL_STEP != newRow && _row - SMALL_STEP != newRow)
        {
            return EXIT_FAILURE;
        }
    }
    else if (rowBigStep)
    {
        if (_col + SMALL_STEP != newCol && _col - SMALL_STEP != newCol)
        {
            return EXIT_FAILURE;
        } 
    }
    return EXIT_SUCCESS;
}

/**
* prints the piece to the board
*/
void Horse::printPiece()
{
    if (_player == WHITE)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[37;42m\u265E\33[0m";
        }
        else
        {
            std::cout << "\33[37;46m\u265E\33[0m";
        }
    }
    else if (_player == BLACK)
    {
        if((_row + _col) % 2)
        {
            std::cout << "\33[30;42m\u265E\33[0m";
        }
        else
        {
            std::cout << "\33[30;46m\u265E\33[0m";
        }
    }
}
