// GamePiece.cpp

#include "GamePiece.h"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GamePiece.
// --------------------------------------------------------------------------------------


/**
 * Moves the piece to a new position
 * @param row the new row
 * @param col the new column
 */
void GamePiece::move(int row, int col)
{
    setCol(col);
    setRow(row);
}
