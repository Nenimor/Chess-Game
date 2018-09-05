// Runner.h

#ifndef EX2_RUNNER_H
#define EX2_RUNNER_H

#include "GamePiece.h"

/**
 * This class represents a runner game piece. inherits from GamePiece
 */
class Runner : public GamePiece
{
public:
    /**
     * a Constructor for a new Queen.
     * @param line the line of the piece
     * @param row the row of the piece
     * @param player number of player, 1=WHITE, 2=BLACK
     * @param isAlive
     */
    Runner(int col, int row, int player, bool isAlive = true) : GamePiece(col, row, player, isAlive)
    {

    }

    /**
     * Checks legality of move - if the move is legal for that particular piece and if necessary checks if other
     * pieces are in the route
     * @param newRow the new row
     * @param newCol the new column
     * @param board the current playing board
     * @return
     */
    int checkMove(int newRow, int newCol, GamePiece* (&board)[BOARD_DIM][BOARD_DIM]) override;

    /**
    * prints the piece to the board
    */
    void printPiece() override;

    /**
     * returns the type of the piece
     * @return type of the piece - string representation
     */
    string getType() override
    {
        return "Runner";
    }
};


#endif //EX2_RUNNER_H
