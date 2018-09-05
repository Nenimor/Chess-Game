// Castle.h

#ifndef EX2_CASTLE_H
#define EX2_CASTLE_H

#include "GamePiece.h"

/**
 * This class represents a Castle game piece. inherits from GamePiece
 */
class Castle : public GamePiece
{
public:
    /**
     * a Constructor for a new Queen.
     * @param line the line of the piece
     * @param row the row of the piece
     * @param player number of player, 1=WHITE, 2=BLACK
     * @param isAlive
     */
    Castle(int col, int row, int player, bool isAlive = true) : GamePiece(col, row, player, isAlive)
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
        return "Castle";
    }

    /**
     * returns true if the piece has already moved once, false otherwise
     * @return returns true if the piece has already moved once, false otherwise
     */
    bool hasMoved() const;

    /**
     * Moves the piece to a new position
     * @param row the new row
     * @param col the new column
     */
    void move(int row, int col) override;

private:
    bool _hasMoved = false; /** indicator for first movement */
};


#endif //EX2_CASTLE_H
